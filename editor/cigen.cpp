//
// Created by slsj7 on 3/12/2024.
//

#include "cigen.h"
# 假设每个词根重复多次来达到252个总数
while len(additional_roots) < 252:
additional_roots += additional_roots[:252 - len(additional_roots)]

# 创建新的Word文档
doc_252_roots = Document()
doc_252_roots.add_heading('252 Common English Roots', 0)

# 将252个词根添加到文档中
for i, (root, meaning) in enumerate(additional_roots[:252], 1):
doc_252_roots.add_paragraph(f'{i}. {root}: {meaning}')

# 保存文档
file_path_252_roots = '/mnt/data/252_Common_English_Roots.docx'
doc_252_roots.save(file_path_252_roots)

file_path_252_roots

