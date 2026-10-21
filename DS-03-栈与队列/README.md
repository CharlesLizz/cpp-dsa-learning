# 第三章 ： 堆栈与队列

## 3.1.1 栈（Stack）的基本概念

### 栈的定义

栈（Stack）是一种只允许在一端进行插入和删除操作的线性表。

**重要术语：**

- **栈顶（Top）**：允许插入和删除的一端。
- **栈底（Bottom）**：另一端。
- **空栈**：不包含任何数据元素的栈。

#### 栈的特点

**后进先出（Last In First Out，LIFO）**。

例如，依次将 `10、20、30` 入栈，出栈顺序只能是 `30、20、10`。

### 栈相关的基本操作

| 操作 | 含义 |
|---|---|
| `InitStack(&S)` | 初始化栈，构造空栈 |
| `DestroyStack(&S)` | 销毁栈，释放其占用的资源 |
| `Push(&S, x)` | 将元素 `x` 压入栈顶 |
| `Pop(&S, &x)` | 弹出栈顶元素，并通过 `x` 返回 |
| `GetTop(S, &x)` | 读取栈顶元素，但不删除 |
| `StackEmpty(S)` | 判断栈是否为空 |

注：具体函数的参数和返回值可能因教材而异。`&S`、`&x` 是常见的算法描述写法；在 C 语言中，通常使用指针传参实现相应功能。

#### 常见考题

给出一定的进栈顺序，判断哪些出栈序列合法；或者给定出栈序列，判断其能否通过合法的入栈、出栈操作得到。

**判断方法：**

按照给定的入栈顺序模拟操作，每当栈顶元素与目标出栈序列的下一个元素相同时，就可以将其弹出。如果最终无法得到目标序列，则该序列不合法。

**Tips：卡特兰数（Catalan Number）**

对于 `n` 个不同元素按照固定顺序入栈，所有可能的合法出栈序列数量为：

\[
C_n=\frac{1}{n+1}\binom{2n}{n}
\]

例如：

- `n = 1`：1 种。
- `n = 2`：2 种。
- `n = 3`：5 种。
- `n = 4`：14 种。

理解即可，重点还是掌握具体序列的合法性判断。

---

## 3.1.2 栈的顺序存储实现（顺序栈）

### 顺序栈的定义

顺序栈使用数组存储栈中的元素，并使用 `top` 记录栈顶位置。

以下采用 **`top = -1` 表示空栈** 的实现方式。

```c
#include <stdbool.h>

#define MaxSize 10

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize]; // 存放栈元素
    int top;                // 栈顶元素的下标
} SqStack;

// 初始化栈
void InitStack(SqStack *S) {
    S->top = -1;
}

// 判断栈空
bool StackEmpty(SqStack S) {
    return S.top == -1;
}

// 入栈
bool Push(SqStack *S, ElemType x) {
    if (S->top == MaxSize - 1) {
        return false; // 栈满
    }

    S->data[++S->top] = x;
    return true;
}

// 出栈
bool Pop(SqStack *S, ElemType *x) {
    if (StackEmpty(*S) || x == NULL) {
        return false;
    }

    *x = S->data[S->top--];
    return true;
}

// 获取栈顶元素，不删除
bool GetTop(SqStack S, ElemType *x) {
    if (StackEmpty(S) || x == NULL) {
        return false;
    }

    *x = S.data[S.top];
    return true;
}
```

### `top` 的含义

在上述实现中，`top` 是栈顶元素的数组下标，而不是栈中元素的个数。

| 状态 | `top` | 栈中元素个数 |
|---|---:|---:|
| 空栈 | `-1` | `0` |
| 一个元素 | `0` | `1` |
| 两个元素 | `1` | `2` |
| 栈满 | `MaxSize - 1` | `MaxSize` |

**为什么入栈写成 `data[++top] = x`？**

先将 `top` 加 `1`，再把新元素放入对应位置。

**为什么出栈写成 `x = data[top--]`？**

先读取当前栈顶元素，再将 `top` 减 `1`。数组中的旧值不必清除，因为它已经不属于当前栈的有效范围。

### 另一种栈顶指针定义

有些教材使用 `top = 0` 表示空栈，此时 `top` 指向下一个可存放元素的位置。

入栈：

```c
S.data[S.top++] = x;
```

出栈：

```c
x = S.data[--S.top];
```

此时栈空条件为 `top == 0`，栈满条件为 `top == MaxSize`。

**注意：** 两种实现都可以，但不能混用。必须根据 `top` 的定义确定初始化、入栈、出栈和判空判满条件。

### 顺序栈的复杂度

| 操作 | 时间复杂度 |
|---|---|
| 初始化 | \(O(1)\) |
| 判空 | \(O(1)\) |
| 入栈 | \(O(1)\) |
| 出栈 | \(O(1)\) |
| 读取栈顶 | \(O(1)\) |

以上为基本操作的时间复杂度。这里采用固定容量数组，因此栈的容量受 `MaxSize` 限制。

### 共享栈

共享栈是指两个栈共用同一片数组空间，以提高空间利用率。

假设数组下标为 `0` 到 `MaxSize - 1`：

- 栈 `S1` 从数组左侧向右增长，初始 `top1 = -1`。
- 栈 `S2` 从数组右侧向左增长，初始 `top2 = MaxSize`。
- 当 `top1 + 1 == top2` 时，共享栈空间已满。

```c
#define MaxSize 10

typedef struct {
    ElemType data[MaxSize];
    int top1;
    int top2;
} SharedStack;

// 初始化
void InitSharedStack(SharedStack *S) {
    S->top1 = -1;
    S->top2 = MaxSize;
}
```

共享栈的入栈方向相反：

- `S1` 入栈：`data[++top1] = x`。
- `S2` 入栈：`data[--top2] = x`。

**注意：** 栈 `S1` 的栈顶指针不能与栈 `S2` 的栈顶指针相遇，否则会发生空间冲突。

---

## 3.1.3 栈的链式存储实现（链栈）

### 链栈的定义

链栈使用链表存储栈元素，本质上与单链表类似。

通常将链表头部作为栈顶，使入栈和出栈不需要遍历整个链表。

```c
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LiStack;
```

这里使用 `LiStack` 表示指向栈顶节点的指针，不额外设置头结点。

### 初始化链栈

```c
void InitStack(LiStack *S) {
    *S = NULL;
}
```

此时 `*S` 是栈顶指针，`NULL` 表示空栈。

### 入栈

```c
bool PushLink(LiStack *S, ElemType x) {
    LinkNode *s = malloc(sizeof(LinkNode));

    if (s == NULL) {
        return false;
    }

    s->data = x;
    s->next = *S;
    *S = s;

    return true;
}
```

新节点插入链表头部，成为新的栈顶。

### 出栈

```c
bool PopLink(LiStack *S, ElemType *x) {
    if (S == NULL || *S == NULL || x == NULL) {
        return false;
    }

    LinkNode *p = *S;
    *x = p->data;
    *S = p->next;

    free(p);
    return true;
}
```

出栈过程：

1. 保存原栈顶节点。
2. 读取栈顶数据。
3. 让栈顶指针指向下一个节点。
4. 释放原栈顶节点。

### 链栈的特点

- 入栈、出栈的时间复杂度均为 \(O(1)\)。
- 不需要预先分配固定大小的数组。
- 容量受可用内存限制。
- 每个节点需要额外存储指针，且动态内存分配可能带来额外开销。

---

## 3.2.1 队列（Queue）的基本概念

### 队列的定义

队列（Queue）是一种只允许在一端进行插入、在另一端进行删除的线性表。

可以类比排队：新来的人从队尾加入，先排队的人从队头离开。

**重要术语：**

- **队头（Front）**：允许删除的一端。
- **队尾（Rear）**：允许插入的一端。
- **空队列**：不包含任何数据元素的队列。

### 队列的特点

**先进先出（First In First Out，FIFO）**。

例如，依次入队 `10、20、30`，出队顺序为 `10、20、30`。

### 队列相关的基本操作

| 操作 | 含义 |
|---|---|
| `InitQueue(&Q)` | 初始化队列 |
| `DestroyQueue(&Q)` | 销毁队列并释放资源 |
| `EnQueue(&Q, x)` | 将元素 `x` 加入队尾 |
| `DeQueue(&Q, &x)` | 删除队头元素并返回 |
| `GetHead(Q, &x)` | 读取队头元素，不删除 |
| `QueueEmpty(Q)` | 判断队列是否为空 |

队列的基本操作需要遵循先进先出的规则，不能像栈一样只在同一端完成插入和删除。

---

## 3.2.2 队列（Queue）的顺序实现

### 顺序队列的实现

顺序队列使用数组存储队列元素，并通过 `front` 和 `rear` 管理队头与队尾。

常见实现采用**循环队列**，以解决普通顺序队列删除元素后，数组前部空间无法直接重复利用的问题。

以下采用牺牲一个存储单元区分队空与队满的实现方式。

```c
#include <stdbool.h>

#define MaxSize 10

typedef struct {
    ElemType data[MaxSize];
    int front;
    int rear;
} SqQueue;

// 初始化队列
void InitQueue(SqQueue *Q) {
    Q->front = Q->rear = 0;
}

// 判断队空
bool QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

// 判断队满
bool QueueFull(SqQueue Q) {
    return (Q.rear + 1) % MaxSize == Q.front;
}

// 入队
bool EnQueue(SqQueue *Q, ElemType x) {
    if (QueueFull(*Q)) {
        return false;
    }

    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;

    return true;
}

// 出队
bool DeQueue(SqQueue *Q, ElemType *x) {
    if (QueueEmpty(*Q) || x == NULL) {
        return false;
    }

    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;

    return true;
}

// 获取队头元素
bool GetHead(SqQueue Q, ElemType *x) {
    if (QueueEmpty(Q) || x == NULL) {
        return false;
    }

    *x = Q.data[Q.front];
    return true;
}
```

### 循环队列的核心原理

#### 1. 为什么使用取模运算？

普通数组的下标从 `0` 增长到 `MaxSize - 1`。循环队列需要在到达数组末尾后，重新回到下标 `0`。

```c
Q->rear = (Q->rear + 1) % MaxSize;
```

例如，`MaxSize = 10`：

- `rear = 8`，下一位置为 `9`。
- `rear = 9`，下一位置为 `(9 + 1) % 10 = 0`。

这样就能循环利用数组空间。

#### 2. 队空条件

```c
Q.front == Q.rear
```

队头指针和队尾指针相等时，队列为空。

#### 3. 队满条件

```c
(Q.rear + 1) % MaxSize == Q.front
```

如果队尾指针再前进一步就会与队头指针重合，则认为队列已满。

由于牺牲了一个存储单元，因此数组容量为 `MaxSize` 时，最多只能存放 `MaxSize - 1` 个元素。

#### 4. 当前元素个数

循环队列中元素个数可以通过以下公式计算：

\[
(\text{rear}+\text{MaxSize}-\text{front})\bmod\text{MaxSize}
\]

例如，`MaxSize = 10`、`front = 7`、`rear = 2`：

\[
(2+10-7)\bmod 10=5
\]

说明队列中有 `5` 个元素。

### 为什么要牺牲一个存储单元？

如果所有数组空间都允许使用，那么 `front == rear` 既可能表示队空，也可能表示队满。

为了区分两种状态，牺牲一个存储单元作为判断依据。

如果题目要求不能牺牲存储单元，可以采用其他方式区分队空和队满。

#### 方式一：增加 `size`

使用 `size` 记录当前元素个数：

- 队空：`size == 0`。
- 队满：`size == MaxSize`。
- 入队成功后，`size++`。
- 出队成功后，`size--`。

#### 方式二：增加 `tag`

使用 `tag` 记录最近一次成功操作的类型：

- 入队成功后，设置 `tag = 1`。
- 出队成功后，设置 `tag = 0`。
- 当 `front == rear` 时，根据 `tag` 判断队空还是队满。

该方法需要正确处理初始化以及每次操作对 `tag` 的更新。

**注意：** 只有当队头、队尾指针相等时，才需要借助 `tag` 区分队空与队满；其他情况下可以直接判断。

### 循环队列的复杂度

| 操作 | 时间复杂度 |
|---|---|
| 初始化 | \(O(1)\) |
| 判空、判满 | \(O(1)\) |
| 入队 | \(O(1)\) |
| 出队 | \(O(1)\) |
| 获取队头 | \(O(1)\) |

---

## 3.2.3 队列（Queue）的链式实现（链队列）

### 1. 链队列的定义

链队列使用链表存储队列元素，通常同时保存队头指针 `front` 和队尾指针 `rear`。

```c
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front;
    LinkNode *rear;
} LinkQueue;
```

使用两个指针可以避免每次入队都遍历寻找队尾。

### 2. 带头结点的链队列

带头结点时，`front` 指向头结点，`rear` 指向最后一个有效数据节点；空队列时，`front == rear`。

#### 初始化

```c
#include <stdlib.h>
#include <stdbool.h>

bool InitQueue(LinkQueue *Q) {
    Q->front = malloc(sizeof(LinkNode));

    if (Q->front == NULL) {
        Q->rear = NULL;
        return false;
    }

    Q->front->next = NULL;
    Q->rear = Q->front;

    return true;
}
```

#### 判空

```c
bool IsEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}
```

#### 入队

```c
bool EnQueueLink(LinkQueue *Q, ElemType x) {
    LinkNode *s = malloc(sizeof(LinkNode));

    if (s == NULL) {
        return false;
    }

    s->data = x;
    s->next = NULL;

    Q->rear->next = s;
    Q->rear = s;

    return true;
}
```

#### 出队

```c
bool DeQueueLink(LinkQueue *Q, ElemType *x) {
    if (Q->front == Q->rear || x == NULL) {
        return false;
    }

    LinkNode *p = Q->front->next;
    *x = p->data;

    Q->front->next = p->next;

    // 如果删除的是最后一个有效节点，恢复空队列状态
    if (Q->rear == p) {
        Q->rear = Q->front;
    }

    free(p);
    return true;
}
```

**关键点：** 如果出队删除的是最后一个有效节点，必须让 `rear` 重新指向头结点，否则 `rear` 会成为悬空指针。

#### 销毁

```c
void DestroyQueue(LinkQueue *Q) {
    LinkNode *p = Q->front;

    while (p != NULL) {
        LinkNode *next = p->next;
        free(p);
        p = next;
    }

    Q->front = NULL;
    Q->rear = NULL;
}
```

销毁时需要释放头结点以及所有有效数据节点。

### 3. 不带头结点的链队列

不带头结点时，`front` 和 `rear` 都直接指向有效数据节点。

空队列时：

```c
Q->front = NULL;
Q->rear = NULL;
```

入队时：

- 如果原队列为空，令 `front` 和 `rear` 都指向新节点。
- 如果原队列非空，将新节点连接到原队尾，再更新 `rear`。

出队时：

- 释放原队头节点。
- 让 `front` 指向下一个节点。
- 如果删除后队列为空，还必须将 `rear` 置为 `NULL`。

### 4. 链队列的特点

- 入队、出队的时间复杂度通常为 \(O(1)\)。
- 不需要像固定容量的顺序队列那样预先分配整块数组空间。
- 一般不会因数组容量固定而队满，但仍然可能因内存不足而无法申请新节点。
- 使用动态内存时，需要正确释放节点，避免内存泄漏。

---

## 3.2.4 双端队列

### 1. 双端队列的定义

普通队列只允许在一端插入、另一端删除。

双端队列（Deque）允许在两端进行插入和删除操作。

#### 输入受限的双端队列

只允许从一端插入，但允许从两端删除。

#### 输出受限的双端队列

允许从两端插入，但只允许从一端删除。

### 2. 出栈、出队序列的合法性判断

常见考题会给定输入序列，判断某个输出序列能否通过指定的数据结构得到。

- **栈：** 只能在同一端进行插入和删除，遵循后进先出。
- **队列：** 在队尾插入、队头删除，遵循先进先出。
- **输入受限的双端队列：** 插入端受限，删除端有两个选择。
- **输出受限的双端队列：** 插入端有两个选择，删除端受限。

解题时应按照允许的操作逐步模拟，不能仅凭输出序列的大小顺序判断。

### 3. 与共享栈的区别

共享栈是两个栈共享同一个数组空间，主要解决空间利用率问题。

双端队列则是一种允许在两端进行插入和删除的数据结构。

两者的定义和应用场景不同，不要混淆。

---

## 3.3.1 栈在括号匹配中的应用

### 1. 问题描述

判断表达式中的括号是否匹配。

例如：

```c
int x = 10 * (20 * (1 + 1) - (3 - 2));
```

其中括号需要正确配对。

### 2. 基本思路

使用栈保存尚未匹配的左括号。

1. 从左向右扫描表达式。
2. 遇到左括号，将其压入栈中。
3. 遇到右括号，如果栈为空，说明没有与之匹配的左括号，匹配失败。
4. 如果栈非空，弹出栈顶左括号，检查括号类型是否匹配。
5. 扫描结束后，如果栈为空，则匹配成功；否则仍有左括号没有匹配，匹配失败。

需要支持的括号类型通常包括：

- `()`
- `[]`
- `{}`

### 3. C 语言实现

```c
#include <stdbool.h>

bool BracketCheck(const char *str) {
    char stack[1000];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        // 左括号入栈
        if (c == '(' || c == '[' || c == '{') {
            if (top == 999) {
                return false;
            }

            stack[++top] = c;
        }
        // 右括号进行匹配
        else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) {
                return false;
            }

            char left = stack[top--];

            if ((c == ')' && left != '(') ||
                (c == ']' && left != '[') ||
                (c == '}' && left != '{')) {
                return false;
            }
        }
    }

    // 所有左括号都必须得到匹配
    return top == -1;
}
```

### 4. 匹配失败的情况

1. **右括号单独出现：** 例如 `())`，扫描到最后一个右括号时栈为空。
2. **左括号没有匹配：** 例如 `(()`，扫描结束后栈不为空。
3. **左右括号类型不匹配：** 例如 `(]`，栈顶左括号与当前右括号不对应。

### 5. 复杂度分析

设表达式长度为 \(n\)。

- 时间复杂度：\(O(n)\)，每个字符最多处理一次。
- 空间复杂度：\(O(n)\)，最坏情况下所有字符都是左括号。

---

