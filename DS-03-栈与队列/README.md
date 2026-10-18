# 第三章 ： 堆栈与队列

## 3.1.1栈（Stack）的基本概念

### 栈的定义

栈 是只允许在一段进行插入或者删除操作的线性表（一种特殊的线性表）

**重要术语**：
- 栈顶：允许插入和删除的一段
- 栈底：不允许插入和删除的一段
- 空栈：没有元素的栈空间

#### 栈的特点

后进先出 Last In First Out（LIFO）

### 栈相关的基本操作
- InitStack初始化栈。构造一个空栈S，分配内存空间
- Destroy销毁栈。销毁并释放栈S所占用的内存空间
- Push进栈。若栈S未满，则将x加入，使之成为新栈顶
- Pop出栈。若栈S非空，则弹出栈顶元素，并用x返回
- GetTop读取栈顶元素。若栈S非空，则用x返回栈顶元素（查）

#### 其他操作

- StackEmpty判断一个栈S是否为空，若S为空，则返回true，否则返回false

#### 常见考题

给出一定的进栈顺序，然后找出合法的出栈顺序

或者给出一些元素使其顺序入栈，判断一个组合是否合法

**Tips**：出入栈操作可以穿插进行，可以用卡特兰（Catalan）数，计算出栈元素不同排列的个数，可以用数学归纳法证明（了解即可

## 3.1.2栈的顺序存储实现（顺序栈）

### 顺序栈的定义

```c伪码
#define MaxSize 10
typedef struck{
	ElemType data[MaxSize];		//静态数组存放栈元素
	int top;			//栈顶指针（由于用数组实现的，则用伪指针记录下标）
}SqStack;

//初始化栈
void InitStack(SqStack &S){
	S.top = -1;			//初始化栈顶指针
}

//判断栈空
bool StackEmpty(SqStack S){
	if(S.top == -1)
		return true;
	else
		return false;
}

//入栈
bool Push(SqStack &S,ElemType x){
	if(S.top == MaxSize-1)
		return false;		//栈满
	S.data[++S.top] = x;		//新元素入栈
	return true;
}

//出栈
bool Pop(SqStack &S,ElemType &x){
	if(S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}


```

### 共享栈

两个栈共用一片空间

比如一个数组中，S1从下标为0的位置开始存，S2从下标为MaxSize的地方开始存

## 3.1.3栈的链式存储实现（链栈）

本质上与单链表相似，可以将头节点后的第一个节点，视为栈顶；且插入删除操作（即出入栈操作）只能从栈顶一端进行（链头作为栈顶）

定义：
	
```c伪码
typedef struct Linknode{
	ElemType data;
	struct Linknode* next;
}* LiStack;
```

## 3.2.1队列（Queue）的基本概念

队列（Queue） 是只允许在一段进行插入操作，在另一端进行删除操作的线性表（本质上也是一种特殊的线性表）

**Tips**：就行排队一样，来的新人只能从队伍尾开始排队

**重要术语**：
- 队头。允许删除的一端
- 队尾。允许插入的一端
- 空队列

**队列的特点**：先进先出First In First Out（FIFO）

### 队列相关的基本操作

- InitQueue初始化队列。构造一个空队列Q
- DestroyQueue销毁队列。销毁并释放队列Q所占用的内存空间
- EnQueue入队。若队列Q未满，将x加入，使之成为新的队尾
- DeQueue出队。若队列Q非空，删除队头元素，并用x返回
- GetHead读取队头元素。若队列Q非空，则将队头元素赋值给x

#### 其他常用操作

- QueueEmpty判队列空。若队列Q为空返回true，否则返回false

## 3.2.2队列（Queue）的顺序实现

### 顺序队列的实现

```c伪码
//定义队列
#define MaxSize 10
typedef struct{
	ElemType data[MaxSize];		//用静态数组存放队列元素
	int front ,rear;		//队头指针，队尾指针
}SqQueue;

//初始化队列
void InitQueue(SqQueue &Q){
	//初始化时 队头、队尾指针指向0
	Q.rear = Q.front = 0;
}

//判断队列是否为空
bool QueueEmpty(SqQueue Q){
	if(Q.rear == Q.front)		//队空条件
		return true;
	else
		return false;
}

//入队
bool EnQueue(SqQueue &Q,ElemType x){
	if((Q.rear+1)%MaxSize == Q.front)	//(Q.rear+1)%MaxSize == Q.front 如果队尾后一个元素的位置是队头，意味着队列已经满了
		return false;
	Q.data[Q.rear] = x
	Q.rear = (Q.rear + 1) % MaxSize;	//队尾指针+1后取模
	return true;
}

//出队
bool DeQueue(SqQueue &Q,ElemType &x){
	if()Q.rear == Q.front)			//队列空
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front+1)%MaxSize;
	return true;
}

//获取队头元素的值，用x返回
bool GetHead(SqQueue Q,ElemType &x){
	if(Q.rear == Q.front)			//Q.rear == Q.front 如果队尾指针和队头指针指向一个位置，意味着队列已经空了
		return false;
	x = Q.data[Q.front];
	return true;
}





```

**Tips1**：进行入队操作时，如果先入队到队列满，再进行有限次（小于总队列元素数）出队操作，则front前出现空位，可以通过rear = rear+1后取模来进行入队操作，从线状的利用空间变成环状的利用空间

**Tips2**：有些地方也会使用 a MOD b 来代表取模运算

**Tips3**：可以用 （rear+MaxSize-front）% MaxSize 的方式来计算队列中的元素个数

#### 个别题目要求不能通过牺牲一块区域的方式 来判断队满还是空，此时我们可以通过

- 增加变量size，记录队列中存储的元素个数
- 增加变量tag，每次删除操作成功时，使tag = 0；每次插入成功时，令tag = 1。又有 只有删除操作会使队空，只有插入操作会使队满

## 3.2.3队列（Queue）的链式实现（链队列）

```c伪码
//链式队列节点
typedef struct LinkNode{
	ElemType data;
	struct LinkNode* next;
}LinkNode;

//链式队列
typedef struct{
	LinkNode* front,rear;		//同时保存队尾和队首两个指针
}LinkQueue;

//初始化队列（带头节点）
void InitQueue(LinkQueue &Q){
	//初始化时 front和rear都指向头节点
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}




```








