//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/dir.h>
#include <unistd.h>

using namespace std;

/*
 * 附录 A：循环冗余校验（CRC）算法
 * CRC 校验（Cyclic Redundancy Check）是一种数据传输错误检查方法， CRC 码两个字
 * 节，包含一 16 位的二进制值。它由传输设备计算后加入到数据包中。接收设备重新计算收
 * 到消息的 CRC，并与接收到的 CRC 域中的值比较，如果两值不同，则有误。
 * 具体算法如下：
 * CRC 是先调入一值是全“1”的 16 位寄存器，然后调用一过程将消息中连续的 8 位字
 * 节各当前寄存器中的值进行处理。仅每个字符中的 8Bit 数据对 CRC 有效，起始位和停止位
 * 以及奇偶校验位均无效。
 * CRC 校验字节的生成步骤如下：
 * ① 装一个 16 位寄存器，所有数位均为 1。
 * ② 取被校验串的一个字节与 16 位寄存器的高位字节进行“异或”运算。运算结果放
 * 入这个 16 位寄存器。 Takes one byte of the checksum and performs xor with the high byte of the 16-bit register.
 * Operation result Into this 16-bit register.
 * ③ 把这个 16 寄存器向右移一位。
 * ④ 若向右（标记位）移出的数位是 1，则生成多项式 1010 0000 0000 0001 和这个寄
 * 存器进行“异或”运算；若向右移出的数位是 0，则返回③。
 * ⑤ 重复③和④，直至移出 8 位。
 * ⑥ 取被校验串的下一个字节
 * ⑦ 重复③~⑥，直至被校验串的所有字节均与 16 位寄存器进行“异或”运算，并移位
 * 8 次。
 * ⑧ 这个 16 位寄存器的内容即 2 字节 CRC 错误校验码。
 * 校验码按照先高字节后低字节的顺序存放。
 *
 *
 *
 * */
unsigned short crc16(const unsigned char *ptr, int len)        // ptr 为数据指针，len 为数据长度
{

    unsigned int i;
    unsigned short j, tmp, CRC16;

    CRC16 = 0xffff;
    for (i = 0; i < len; i++) {
        CRC16 = *ptr ^ CRC16;
        for (j = 0; j < 8; j++) {
            tmp = CRC16 & 0x0001;
            CRC16 = CRC16 >> 1;
            if (tmp)
                CRC16 = CRC16 ^ 0xa001;
        }
        ptr++;
    }

    return (CRC16);
}

unsigned short checkFile(const char *file) {
    struct stat stFileStat;

    int ret = stat(file, &stFileStat);
    if (ret < 0) {
        perror("stat error");
        return false;
    }

    cout << "file size = " << stFileStat.st_size << endl;

    char *p = new char[stFileStat.st_size + 2];

    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        perror("fopen file error");
        return -1;
    }

    ret = fread(p, stFileStat.st_size, 1, fp);
    if (ret != 1) {
        perror("fread error");
        return -1;
    }

    fclose(fp);
    unsigned short crc16Data = crc16((unsigned char *) p, stFileStat.st_size);
    // printf("file crc16 = 0x%04x\n", crc16Data);

    delete[] p;

    return crc16Data;
}

// enum
// {
//     DT_UNKNOWN = 0,     //未知类型
//     DT_FIFO = 1,        //管道
//     DT_CHR = 2,         //字符设备文件
//     DT_DIR = 4,         //目录
//     DT_BLK = 6,         //块设备文件
//     DT_REG = 8,         //普通文件
//     DT_LNK = 10,        //连接文件
//     DT_SOCK = 12,       //套接字类型
//     DT_WHT = 14         //
// };

struct my_index {
    char passname[256];
    unsigned long findex;
    unsigned long eindex;
    unsigned long nindex;
};

struct frame_biosnoop {
    unsigned long sector_num;
    unsigned long offset;
    // char ibuf[32 * 1024 * 1024];
    // char iseg[64000];
};

struct LListNode {
    LListNode *next;
    LListNode *pre;
    int key;
    int val;

    LListNode() : key(0), val(0), next(nullptr), pre(nullptr) {}

    LListNode(int k, int v) : key(k), val(v), next(nullptr), pre(nullptr) {}
};

class DList {
public:
    LListNode *head;
    LListNode *tail;

    DList() {
        head = new LListNode();
        tail = new LListNode();
        head->next = tail;
        tail->pre = head;
    }

    void removeNode(LListNode *node) {
        // auto tmp = node;
        node->pre->next = node->next;
        node->next->pre = node->pre;
        delete node;
    }

    void setAsHead(LListNode *node) {
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
        node->pre = head;
    }

    int getKey(LListNode *node) {
        return node->val;
    }

    void moveHead(LListNode *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        setAsHead(node);
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, LListNode *> ma;
    DList dl;
    int size;

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    int get(int key) {
        if (ma.count(key)) {
            dl.moveHead(ma[key]);
            return ma[key]->val;

        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (ma.count(key)) {
            ma[key]->val = value;
            dl.moveHead(ma[key]);
        } else {
            auto node = new LListNode(key, value);
            size++;
            if (size <= cap) {
                ma[key] = node;
                dl.setAsHead(node);
            } else {
                ma[key] = node;
                ma.erase(dl.tail->pre->key);
                dl.removeNode(dl.tail->pre);
                --size;
                dl.setAsHead(node);
            }
        }
    }
};

map<string, struct my_index *> mymap;

void find_st(char *url) {
    assert(url[0] == '/');
    char *base_str = strrchr(url, '/');
    // int pos = (int) (base_str - url);
    char file_name[256] = "";
    strcat(file_name, base_str);
    // printf("%d ", strcmp(file_name,"."));
    if (!strcmp(file_name, "/.") or !strcmp(file_name, "/..")) {
        return;
    }

    struct stat st_buf;
    int rc = stat(url, &st_buf);

    if (rc != 0) {
        fprintf(stderr, "something wrong :rc %d\n", rc);
        return;
    }


    if (S_ISDIR(st_buf.st_mode)) {
        struct dirent *pdirent;

        DIR *d_info = opendir(url);
        if (d_info) {
            while ((pdirent = readdir(d_info)) != NULL) {
                if (!mymap.count(url)) {
                    // struct my_index m_ind;
                    // my_index *m = &m_ind;
                    my_index *m = (my_index *) malloc(sizeof(struct my_index));
                    strcpy(m->passname, url);
                    m->findex = st_buf.st_ino;
                    m->eindex = st_buf.st_ino;
                    m->nindex = 1;
                    mymap[url] = m;
                    // free(m);
                } else {
                    my_index *m = mymap[url];
                    m->eindex = pdirent->d_ino;
                    m->nindex++;
                }

                if (pdirent->d_type & DT_REG) {
                    // 文件
                    char dir_name[1024];
                    strcpy(dir_name, url);
                    strcat(dir_name, "/");
                    strcat(dir_name, pdirent->d_name);
                    printf("%s ,check 0x%04x \n", dir_name, checkFile(dir_name));
                    // continue;
                }
                if (pdirent->d_type & DT_DIR) {
                    char dir_name[256];
                    strcpy(dir_name, url);
                    strcat(dir_name, "/");
                    strcat(dir_name, pdirent->d_name);
                    find_st(dir_name);
                }

            }
        }
        // dir
        closedir(d_info);
    }
    // if (S_ISREG(st_buf.st_mode)) {
    //     if (!mymap.count(url)) {
    //         // my_index *m;
    //         my_index *m = (my_index *)malloc(sizeof(struct my_index));
    //         strcpy(m->passname, url);
    //         m->findex = st_buf.st_ino;
    //         m->eindex = st_buf.st_ino;
    //         m->nindex = 1;
    //         mymap[url] = m;
    //     } else{
    //         my_index *m = mymap[url];
    //         m->eindex = st_buf.st_ino;
    //         m->nindex++;
    //     }
    // }
    // int fd = open(url, O_RDONLY);
}

struct bucket {
    int fframe;
    int eframe;
    int npg;
};

int lru_seg(char *url) {
    uint32_t smax = 0;
    uint32_t smin = 0xffffffff;
    // read file
    struct stat stFileStat;

    int ret = stat(url, &stFileStat);
    if (ret < 0) {
        perror("stat error");
        return false;
    }

    cout << "file size = " << stFileStat.st_size << endl;

    // char *p = new char[stFileStat.st_size + 2];
    char p[4096];

    FILE *fp = fopen(url, "r");
    if (fp == NULL) {
        perror("fopen file error");
        return -1;
    }

    // while(fgets(p, MAX_LEN, fp))
    int fim = 0;
    long long sector_num, offset;
    // while (fscanf(fp, "%lld %lld\n", &sector_num, &offset)) {
    while (fgets(p, 4096, fp)) {
        // fprintf(stderr, "%d \n", strlen(p));
        sscanf(p, "%lld %lld", &sector_num, &offset);
        int pg = sector_num / 8;
        if (pg > smax) {
            smax = pg;
        }
        if (pg < smin) {
            smin = pg;
        }
        // fprintf(stderr, "smax: %d smin %d",smax, smin);
    }
    int npg = smax - smin;
    int remain = 0;
    if (npg % (8 * 1024)) remain = 1;
    int nsegs = npg / (8 * 1024) + remain;
    // fprintf(stderr, "npg: %d nsegs %d\n",npg, nsegs);
    // return 0;

    // calloc 开辟批量数据并初始化
    bucket *t_bucket = (bucket *) calloc(nsegs, sizeof(bucket));
    fclose(fp);
    fp = fopen(url, "r");
    int frame = 0;
    // while (fscanf(fp, "%[^\n]", p)) {
    while (fgets(p, 256, fp)) {
        long long sector_num, offset;
        sscanf(p, "%lld %lld", &sector_num, &offset);
        // page 页大小通常为4kb
        int pg = sector_num / 8;
        pg -= smin;
        npg = offset / 4096;
        int fpg = 0;
        for (int i = 0; i < npg; ++i) {
            fpg = pg + i;
            int seg = fpg / (8 * 1024);
            bucket *t_buck = t_bucket + seg;
            if (t_buck->fframe == 0) {
                t_buck->fframe = frame;
            }
            t_buck->eframe = frame;
            t_buck->npg++;
        }
        frame++;
    }
    int tseg = 0;
    int tpage = 0;
    bucket *t_buck = t_bucket;
    for (int i = 0; i < nsegs; t_buck++, ++i) {
        if (t_buck->npg == 0) {
            continue;
        }
        tseg++;
        tpage += t_buck->npg;
        // printf("%d, %d, %d, %d\n", i, t_buck->fframe, t_buck->eframe, t_buck->npg);
    }
    printf("%d, %d, %d\n", tseg, tpage, tpage / tseg);
    free(t_bucket);

    // ret = fread(p, stFileStat.st_size, 1, fp);
    // if (ret != 1) {
    //     perror("fread error");
    //     return -1;
    // }

    fclose(fp);
    // unsigned short crc16Data = crc16((unsigned char *) p, stFileStat.st_size);
// printf("file crc16 = 0x%04x\n", crc16Data);

    // delete[]
    //         p;
// get frame_biosnoop
// count seg and save
}

int main(int argc, char *argv[]) {
    char pass_dir[] = "/mnt/c/Users/sj/Desktop/sector.txt";
    lru_seg(pass_dir);
    // find_st(pass_dir);
    // for (auto it: mymap) {
    //     printf("%s number :%lu\n", it.second->passname, it.second->nindex - 2);
    //     printf("first: %lu end :%lu\n", it.second->findex, it.second->eindex);
    //     // 在此处析构之前malloc的地址空间， 否则会内存泄漏
    //     free(it.second);
    // }
    return 0;
}