#pragma once

#include <iostream>

namespace DT
{
	/// REGION: Linked list zone.-----------------------]
	template <class T> class LinkedListNode
	{
	private:
		/// Fields --------------------------------------------------------------------------------------------]
		T value;					 /// Value of node.
		LinkedListNode<T>* next;	 /// Pointer to next node.
		LinkedListNode<T>* previous; /// Pointer to previous node.

	public:
		/// Constructors --------------------------------------------------------------------------------------]
		LinkedListNode<T>(T value, LinkedListNode<T>* previus, LinkedListNode<T>* next);

		LinkedListNode<T>(T value);

		LinkedListNode<T>(T value, LinkedListNode<T>* next);

		/// Destructors ---------------------------------------------------------------------------------------]
		~LinkedListNode<T>();

		/// Proporties ----------------------------------------------------------------------------------------]

		/// a) Getters:

		T getValue();


		LinkedListNode<T>* getNext();

		LinkedListNode<T>* getPrevious();

		/// b) Setters:
		
		void setValue(T value);

		void setNext(LinkedListNode<T>* next);

		void setPrevious(LinkedListNode<T>* previous);

		/// Operators overloading --------------------------------------------------------------------------]

		/// a) Printing.

		friend std::ostream& operator<< (std::ostream& out, LinkedListNode<T> cr);

		/// b) Compare.

		friend int operator== (LinkedListNode<T> first, LinkedListNode<T> second);

		friend int operator> (LinkedListNode<T> first, LinkedListNode<T> second);
	};

	template <class T> class LinkedList
	{
	private:
		/// Fields.------------------------------------------------------------------]
		LinkedListNode<T>* head; /// Head of our linked list.
		int length; /// Length of the list.

	public:
		/// Constructors.------------------------------------------------------------]
		LinkedList<T>(T value);

		LinkedList<T>();

		/// Destructors.-------------------------------------------------------------]
		~LinkedList<T>();

		/// Proporties.--------------------------------------------------------------]

		int getLength();

		LinkedListNode<T>* getHead();

		/// Methods.-----------------------------------------------------------------]

		void Add(T value);

		void Remove(T value);

		void Print();

	private:

		/// Helper methods.----------------------------------------------------------]

		void Add(LinkedListNode<T>* node, T value);

		void Remove(LinkedListNode<T>* node, T value);

		void Print(LinkedListNode<T>* node);

		/// Operators overloading.---------------------------------------------------]

		friend std::ostream& operator<<(std::ostream& out, LinkedList<T> list);
	};
	/// END REGION--------------------------------------]

	/// REGION: Stack zone.-----------------------------]
	template <class T> class StackNode
	{
	private:
		/// Fields ----------------------------------------------------]
		T value; /// Value of the node.
		StackNode<T>* next; /// Pointer to the next node.
	public:
		/// Constructors ----------------------------------------------]
		StackNode(T value, StackNode<T>* next);
	
		/// Destructors -----------------------------------------------]
		~StackNode();
	
		/// Proporties -----------------------------------------------]
		T getValue();

		void setValue(T value);

		StackNode<T>* getNext();

		void setNext(StackNode<T>* next);

		/// Operators overloading ------------------------------------]

		/// Print the node.
		friend std::ostream& operator<< (std::ostream& out, StackNode<T> node);

		/// Are equals the nodes.
		friend int operator== (StackNode<T> first, StackNode<T> second);

		friend int operator> (StackNode<T> first, StackNode<T> second);
	};

	template <class T> class Stack
	{
	private:
		/// Fields -----------------------------------------------]
		StackNode<T>* head; /// Head of the stack.
		int n; /// Number of the elements in the stack.
	public:
		/// Constructors-------------------------------------------]
		Stack<T>(T value);

		Stack<T>();

		/// Destructors-------------------------------------------]
		~Stack<T>();

		/// Proporties --------------------------------------------]

		/// a) getters:

		StackNode<T>* getHead();

		int getLength();

		/// Methods ----------------------------------------------]

		void Push(T value);

		T Pop();

		T Peek();

		/// Operators overloading ---------------------------------]

		friend std::ostream& operator<< (std::ostream& out, Stack<T> stack);

	};
	/// END REGION--------------------------------------]

	/// REGION: List zone.------------------------------]
	template <class T> class List
	{
	private:
		/// Fields--------------------------------------]
		T* data; /// Dynamic storage for data.
		int size; /// Size of dynamic storage.
		int n; /// Current index of the element.

	public:
		/// Constructors--------------------------------]
		List<T>(int size);

		List<T>();

		List<T>(int size, T value);

		/// Dentructors---------------------------------]
		~List<T>();

		/// Proporties----------------------------------]
		int getCount();

		T* getData();

		/// Methods-------------------------------------]

		void Add(T value);

		void Remove(T value);

		void ShiftDown(int index);

		int getIndex(T value);

	private:
		/// Helper methods----------------------]
		void Resize();

		/// Operators overloading---------------]

		/// a) Printing.
		friend std::ostream& operator<< (std::ostream& out, List<T> list);
	};
	/// END REGION--------------------------------------]

	/// REGION: Queue zone.-----------------------------]
	template <class T> class QueueNode
	{
	private:
		/// Fields.------------------------------]
		T value; /// Value of the node.
		QueueNode<T>* next; /// Pointer to next node.
	public:
		/// Constructors-------------------------]
		QueueNode<T>(T value, QueueNode<T>* next);

		QueueNode<T>(T value);

		/// Destructors--------------------------]
		~QueueNode<T>();

		/// Proporties---------------------------]

		/// a) Getters.

		T getValue();

		QueueNode<T>* getNext();

		/// b) Setters.

		void setValue(T value);

		void setNext(QueueNode<T>* next);

		/// Operators overloading---------------]

		/// a) Printing.

		friend std::ostream& operator<< (std::ostream& out, QueueNode<T> node);

		/// b) Comparing.

		friend int operator== (QueueNode<T> first, QueueNode<T> second);

		friend int operator> (QueueNode<T> first, QueueNode<T> second);
	};

	template <class T> class Queue
	{
	private:
		/// Fields.----------------------------------------------------]
		QueueNode<T>* front; /// Pointer to the front of the list.
		QueueNode<T>* back; /// Pointer to the back of the list.
		int n; /// Number of elements in the list.

	public:
		/// Constructors.----------------------------------------------]
		Queue<T>();

		/// Destructors.-----------------------------------------------]
		~Queue<T>();

		/// Proporties.------------------------------------------------]

		/// a) Getters.

		QueueNode<T>* getFront();

		QueueNode<T>* getBack();

		int getCount();

		/// Methods.---------------------------------------------------]

		void Enqueue(T value);

		T Dequeue();

		/// Operators overloading.---------------------------------------]

		/// a) Printing.

		friend std::ostream& operator<< (std::ostream& out, Queue<T> queue);
	};
	/// END REGION--------------------------------------]

	/// REGION: Binary search tree zone.----------------]
	template <class T> class BSTNode
	{
	private:
		/// Fields--------------------------------------]
		T value; /// Value of the binary search tree. 
		BSTNode* left; /// Pointer to the left node.
		BSTNode* right; /// Pointer to the right node.

	public:
		/// Constructors--------------------------------]
		BSTNode<T>(T value, BSTNode<T>* left, BSTNode<T>* right);
		BSTNode<T>(T value);

		/// Proporties-----------------------------------]

		/// a) Getters.

		T getValue();

		BSTNode<T>* getLeft();

		BSTNode<T>* getRight();

		/// b) Setters.

		void setValue(T value);

		void setLeft(BSTNode<T>* left);

		void setRight(BSTNode<T>* right);

		/// Operators overloading-----------------------------------]

		/// Printing.

		friend std::ostream& operator<< (std::ostream& out, BSTNode<T> node);
	};

	template<class T> class BST
	{
	private:
		/// Fields.------------------------------------]
		BSTNode<T>* root; /// Pointer to the root of the tree.
		int count; /// Number of the elements in the tree.

	public:
		/// Constructors.------------------------------]
		BST<T>(T value);

		BST<T>();

		/// Proporties. -------------------------------]

		/// a) Getters.

		BSTNode<T>* getRoot();

		int getCount();

		/// Methods. -------------------------------]

		void Add(T value);

		void Print();

	private:

		void Add(BSTNode<T>* node, T value);

		void Print(BSTNode<T>* node);

		/// Operators overloading. -------------------------------------]

		/// a) Printing.

		friend std::ostream& operator<< (std::ostream& out, BST<T> bst);
	};
	/// END REGION.-------------------------------------]

	/// REGION: Heap zone.------------------------------]
	template <class T> class HeapNode
	{
	private:
		/// Fields.-------------------------------------]
		T value; /// Value of the node.
		HeapNode<T>* left; /// Pointer to the left child node.
		HeapNode<T>* right; /// Pointer to the right child node.

	public:
		/// Constructors---------------------------------]
		HeapNode<T>(T value, HeapNode<T>* left, HeapNode<T>* right);

		HeapNode<T>(T value);

		/// Proporties-------------------------------------]

		/// a) Getters.

		T getValue();

		HeapNode<T>* getLeft();

		HeapNode<T>* getRight();

		/// b) Setters.

		void setValue(T value);

		void setLeft(HeapNode<T>* left);

		void setRight(HeapNode<T>* right);

		/// Operators Overloading--------------------------------]

		/// a) Printing.

		friend std::ostream& operator<< (std::ostream& out, HeapNode<T> node);
	};

	template <class T> class Heap
	{
	private:
		/// Fields.-------------------------------------]
		HeapNode<T>* root; /// Pointer to the root of the heap.
		int n; /// Number of nodes in the heap.

	public:
		/// Constructors. ------------------------------]
		Heap<T>(T value);

		Heap<T>();

		/// Destructors.---------------------------------]
		~Heap<T>();

		/// Proporties.----------------------------------]

		/// a) Getters.

		HeapNode<T>* getRoot();

		int getCount();

		/// Methods.--------------------------------------]

		void Add(T value);

		void Print();

	private:

		void Print_InOrder(HeapNode<T>* node);

		void Add(HeapNode<T>* node, T value);
		/// Operators overloading.----------------------------------]

		/// a) Printing.
		friend std::ostream& operator<< (std::ostream& out, Heap<T> heap);
	};
	/// END REGION.-------------------------------------]
}

namespace SA
{
	/// REGION: Sorting algorithms.---------------------]
	template <class T> class SelectionSort
	{
	public:
		static void Sort(T* data, int size);
	};

	template <class T> class BubbleSort
	{
	public:
		static void Sort(T* data, int size);
	};

	template <class T> class GnomeSort
	{
	public:
		static void Sort(T* data, int size);
	};

	template <class T> class InsertionSort
	{
	public:
		static void Sort(T* data, int size);
	};

	template <class T> class ShellSort
	{
	public:
		/// Main function.
		static void Sort(T* array, int n);
	};

	template <class T> class QuickSort
	{
	public:
		/// Main function.
		static void Sort(T* array, int n);
	private:
		/// Helper functions:
		static void Sort(T* array, int lower, int upper);
		static int Partition(T* array, int lower, int upper);
	};

	template <class T> class MergeSort
	{
	public:
		/// Main function.
		static void Sort(T* array, int n);
	private:
		/// Helper functions.
		static void Sort(T* array, int lower, int upper, int n);
		static void Merge(T* array, int lower, int middle, int upper, int n);
	};
	/// END REGION.-------------------------------------]
}
