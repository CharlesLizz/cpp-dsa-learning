# 第三章 ： 堆栈与队列

## 3.1.1栈（Stack）的基本概念

### 栈的定义

栈 是只允许再一段进行插入或者删除操作的线性表（一种特殊的线性表）

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








