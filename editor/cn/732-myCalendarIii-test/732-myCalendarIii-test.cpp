// 2022-06-06 18:29:15
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MyCalendarThree {
public:
    // unordered_map<int, int> tree;
    // unordered_map<int, int> lazy;
    map<int, int> cnt;

    MyCalendarThree() {
    }

    // void update(int start, int end, int l, int r, int node){
    //     if (start > r || end < l){
    //         return;
    //     } else if(start <= l && r <= end){
    //         ++tree[node];
    //         ++lazy[node];
    //     } else{
    //         int left_node = node * 2;
    //         int right_node = left_node + 1;
    //         int mid = l + (r - l) / 2;
    //         update(start, end, l, mid, left_node);
    //         update(start, end, mid + 1, r, right_node);
    //         tree[node] = lazy[node] + max(tree[left_node], tree[right_node]);
    //     }
    // }

    int book(int start, int end){
        int ans = 0;
        int maxBook = 0;
        cnt[start]++;
        cnt[end]--;
        for (auto it : cnt){
            maxBook += it.second;
            ans = max(maxBook, ans);
        }
        return ans;

    }
    // int book(int start, int end) {
    //     update(start, end - 1, 0, 1e9, 1);
    //     return tree[1];
    // }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
//leetcode submit region end(Prohibit modification and deletion)


// namespace {
//     TEST(MyCalendarIii, Example1) {      // NOLINT
//         std::vector<int> nums = {};
//         auto ans = Solution().myCalendarIii(nums);
//         decltype(ans) rightAns =;
//         ASSERT_EQ(ans, rightAns);
//     }
//
// }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    char name[10]; //学生名字
    char sex[2];//性别
    int number;//学号
    int s[3];//各个成绩
    struct student *next;
};

//遍历链表
void fun(struct student *head);

//插入结点
void toadd(struct student *head);//x为要加的个数
//删除结点
void todelet(struct student *head);

//改学生信息
void xinxi(struct student *head);

//用学号改结点
void gai(struct student *head);

//对课程操作
void kecheng(int i, struct student *head);

//按学号排序
void xuehao(struct student *head);

//保存信息
void baocuen(struct student *head);

int main() {
    int x, i, y, p;//x为你输入的选项
    char kc[4], l[3][3];
    int s[100][2];//用来保存账号密码
    s[0][0] = 2022;
    s[0][1] = 2022;
    //printf("请输入三个课程\n");
    /*for(x=0;x<3;x++)
    {scanf("%s",l[x]);
    }*/
    struct student *nat, *mat, *kat;
    nat = (student *) malloc(sizeof(student));
    mat = nat;
    for (; 1;) {
        printf("1为录入，2为插入，3为删除，4为用学号改信息，5为保存信息，6为用课程改信息，7为按学号排序，8为改某人信息\n");
        scanf("%d", &x);
        mat = nat;
        switch (x) {
            case 1:
                fun(mat);
                break;
            case 2:
                toadd(mat);
                break;
            case 3:
                todelet(mat);
                break;
            case 4:
                gai(mat);
                break;
                //保存信息
            case 5:
                baocuen(mat);
                break;
                //由课程名称进行
            case 6:
                scanf("%s", kc);
                for (i = 0; 1; i++)
                    if (strcmp(l[i], kc) == 0) {
                        kecheng(i, mat);
                        break;
                    }
                break;
                //按学号排序
            case 7:
                xuehao(mat);
                break;
                //改某个学生的信息
            case 8:
                xinxi(mat);
        }
        printf("想退出请输入0\n");
        scanf("%d", &p);
        if (p == 0) break;
    }
}

void fun(struct student *he) {
    int m, i, h;
    struct student *p;
    p = (student *) malloc(sizeof(student));
    he = (student *) malloc(sizeof(student));
    p->next = NULL;
    FILE *f1;
    printf("如果想从文件上输入,请按1想从键盘上输入请输入2\n");
    rt :
    scanf("%d", &m);
    if (m == 1) {
        f1 = fopen("int.txt", "r+");
        for (; feof(f1) == 0;) {
            fscanf(f1, "%s", he->name);//名字
            fscanf(f1, "%s", he->sex);//性别
            fscanf(f1, "%d", &he->number);//学号
            for (m = 0; m < 3; m++) {
                fscanf(f1, "%d", &he->s[m]);//各个成绩
            }
            he->next = p;
            he = he->next;
        }
        he->next = NULL;
        fclose(f1);

    } else if (m == 2) {
        printf("请问你想输入几个\n");
        scanf("%d", &m);
        for (i = 0; i < m; i++) {
            scanf("%d", &he->number);
            scanf("%s", &he->sex);
            scanf("%s", &he->name);
            for (int i = 0; i < 3; i++) {
                scanf("%d", &(he->s[i]));//各个成绩
            }
            he->next = p;
            he = he->next;
        }
    } else {
        printf("请你重新输入\n");
        goto rt;
    }
    he->next = NULL;
}

void toadd(struct student *head) {
    int n, m, i;
    printf("你想弄到第几个后面\n");
    scanf("%d", &i);

    FILE *f1;
    struct student *p, *h;
    f1 = fopen("add.txt", "r+");
    for (n = 1; n != i; n++) {
        head = head->next;
    }
    for (n = 0; n < i; n++) {
        fscanf(f1, "%s", p->name);//名字
        fscanf(f1, "%s", p->sex);//性别
        fscanf(f1, "%d", &p->number);//学号
        for (m = 0; m < 3; m++) {
            fscanf(f1, "%d", &p->s[m]);//各个成绩
        }
        p->next = head->next;
        head->next = p;
    }
}

void todelet(struct student *head) {
    int n, i;
    printf("你想删第几个\n");
    scanf("%d", &i);

    struct student *p, *h, *y;
    for (; 1; head = head->next)//找到学号的前一个
    {
        p = head->next;
        if (p->number == i)
            break;
    }
    p = head->next;
    head->next = p->next;
}

void xinxi(struct student *head) {
    int n, y, m, i;
    FILE *f1;
    printf("你想改第几个学生的信息\n");
    scanf("%d", &i);
    f1 = fopen("xinxi.txt", "r+");
    for (n = 1; n < i; n++) {
        head = head->next;
    }
    printf("改名字1，改性别2，改学号3，改成绩4");
    scanf("%d", &y);
    switch (y) {
        case 1:
            fscanf(f1, "%s", head->name);
            break;
        case 2:
            fscanf(f1, "%s", head->sex);
            break;
        case 3:
            fscanf(f1, "%d", &head->number);
            break;
        case 4:
            for (m = 0; m < 3; m++) {
                fscanf(f1, "%d", &head->s[m]);//各个成绩
            }
            break;
    }
}

void gai(struct student *head) {
    int x, y, i;
    struct student *p;
    printf("请输入学号来改信息\n");
    scanf("%d", &i);
    int flag = 0;
    while(head != nullptr){
        if (head->number == i){
            flag = 1;
            break;
        }
        head = head->next;
    }
    if (flag == 0){
        // 没找到该学号 。。。。
        printf("请重新输入\n");
    } else {
        // 找到该学号，处理逻辑。。。。
    }

}

void kecheng(int i, struct student *head) {
    int x, y, z, l;//z为总个数，l不及格人数
    float m;//平均数
    x = head->s[i];//找最高分
    y = head->s[i];//找最低分
    for (; head->next != NULL; head = head->next) {
        m = m + head->s[i];
        if (x < head->s[i])
            x = head->s[i];
        if (y > head->s[i])
            y = head->s[i];
        if (head->s[i] < 60)
            l++;
        z++;
    }
    m = m / z;
    printf("最高分为%d,最低分为%d,不及格数为%d,平均数为%f\n", x, y, l, m);
}

void xuehao(struct student *head) {
    struct student *p, *q, *x, *y;
    for (; p->next != NULL; p = p->next) {
        q = head;
        for (; q->next != NULL; q = q->next) {
            x = p->next;
            if (p->number > x->number) {
                y = x;
                x = p;
                p = y;
            }
        }
    }
}

void baocuen(struct student *head) {
    int i;
    FILE *f1;
    f1 = fopen("out.txt", "w+");
    fprintf(f1, "学号      姓名   性别  科一  科二  科三");
    for (; head->next != 0; head = head->next) {
        fprintf(f1, "%d  %s  %s  ", head->number, head->name, head->sex);
        for (i = 0; i < 3; i++)
            fprintf(f1, "%d  ", head->s[i]);
        fprintf(f1, "\n");
    }
    fclose(f1);

}



// int main(int argc, char *argv[]) {
//
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }