#include <iostream>
#include "SA_DT.h"

namespace DT
{
	// CLASS:: LinkedListNode<T>----------------------------------------------------------------------------------------------]
	/// Constructors --------------------------------------------------------------------------------------]
	template <class T> LinkedListNode<T>::LinkedListNode<T>(T value, LinkedListNode<T>* previus, LinkedListNode<T>* next)
		{
			///TODO: Create the linked list node. <- Everything.
			this->value = value;
			this->next = next;
			this->previous = previous;
		}

	template <class T> LinkedListNode<T>::LinkedListNode<T>(T value)
		{
			///TODO: Create the linked list node. <- Only value.
			this->value = value;
			next = nullptr;
			previous = nullptr;
		}

	template <class T> LinkedListNode<T>::LinkedListNode<T>(T value, LinkedListNode<T>* next)
		{
			///TODO: Create the linked list node. <- Value and pointer to next linked list node.
			this->value = value;
			this->next = next;
			previous = nullptr;
		}

	/// Destructors ---------------------------------------------------------------------------------------]
	template <class T> LinkedListNode<T>::~LinkedListNode<T>()
		{
			/// Dispose resources.
			next = NULL;
			previous = NULL;
			delete next;
			delete previous;
		}

	/// Proporties ----------------------------------------------------------------------------------------]

	/// a) Getters:

	template <class T> T LinkedListNode<T>::getValue()
		{
			/// Return value of the linked list node.
			return value;
		}

	template <class T> LinkedListNode<T>* LinkedListNode<T>:: getNext()
		{
			/// Return pointer to next linked list node.
			return next;
		}

	template <class T> LinkedListNode<T>* LinkedListNode<T>:: getPrevious()
		{
			/// Return pointer to previous linked list node.
			return previous;
		}

	/// b) Setters:

	template <class T> void LinkedListNode<T>::setValue(T value)
		{
			/// Set the new value.
			this->value = value;
		}

	template <class T> void LinkedListNode<T>::setNext(LinkedListNode<T>* next)
		{
			/// Set the pointer to next linked list node.
			this->next = next;
		}

	template <class T> void LinkedListNode<T>::setPrevious(LinkedListNode<T>* previous)
		{
			/// Set the pointer to the previous linked list node.
			this->previous = previous;
		}

	/// Operators overloading --------------------------------------------------------------------------]

	/// a) Printing.

	template <class T> std::ostream& operator<< (std::ostream& out, LinkedListNode<T> cr)
		{
			/// Print the value of linked list node.
			out << "Value: " << cr.getValue() << "\n";
			return out;
		}

	/// b) Compare.

	template <class T> int operator== (LinkedListNode<T> first, LinkedListNode<T> second)
		{
			/// Compare two linked list nodes.
			if (first.getValue() != second.getValue())
			{
				return 0;
			}
			return 1;
		}

	template <class T>  int operator> (LinkedListNode<T> first, LinkedListNode<T> second)
		{
			if (first.getValue() > second.getValue())
			{
				return 1;
			}
			return 0;
		}
	// CLASS:: LinkedListNode<T>----------------------------------------------------------------------------------------------]

	// CLASS: LinkedList<T>------------------------------------------------------------------------]
	/// Constructors.------------------------------------------------------------]
	template <class T> LinkedList<T>::LinkedList<T>(T value)
		{
			/// 1. Setting the head of the linked list node.
			head = new LinkedListNode<T>(value, nullptr, nullptr);

			/// 2. One is start length;
			length = 1;

		}

	template <class T> LinkedList<T>::LinkedList<T>()
		{
			/// DEFAULT_CONSTRUCTOR.
			length = 0;
		}

	/// Destructors.-------------------------------------------------------------]
	template <class T> LinkedList<T>::~LinkedList<T>()
		{
			/// Dispose resources.
			delete head;
		}

	/// Proporties.--------------------------------------------------------------]

	template <class T> int LinkedList<T>::getLength()
		{
			/// Return the length of the list.
			return length;
		}

	template <class T> LinkedListNode<T>* LinkedList<T>:: getHead()
		{
			/// Return head of the list.
			return head;
		}

	/// Methods.-----------------------------------------------------------------]

	template <class T> void LinkedList<T>:: Add(T value)
		{
			/// Adding an element to the back of the list using helper recursive function.
			if (head == nullptr)
			{
				head = new LinkedListNode<T>(value, nullptr, nullptr);
			}
			else
			{
				Add(head, value);
			}
			length++;
		}

	template <class T> void LinkedList<T>:: Remove(T value)
		{
			/// Removing an element from the list using helper recurisive function.
			if (head->getValue() == value && head != nullptr)
			{
				head = head->getNext();
			}
			else
			{
				Remove(head, value);
			}
		}

	template <class T> void LinkedList<T>:: Print()
		{
			/// Printing the list.
			Print(head);
		}

	/// Helper methods.----------------------------------------------------------]

	template <class T> void LinkedList<T>::Add(LinkedListNode<T>* node, T value)
		{
			/// Adding an element to the list.
			if (node->getNext() == nullptr)
			{
				node->setNext(new LinkedListNode<T>(value, node, nullptr));
			}
			else
			{
				Add(node->getNext(), value);
			}
		}

	template <class T> void LinkedList<T>::Remove(LinkedListNode<T>* node, T value)
		{
			/// Removing an element from the list.
			if (node->getNext()->getValue() == value)
			{
				node->setNext(node->getNext()->getNext());
				length--;
			}
			else if (node->getNext() != nullptr)
			{
				Remove(node->getNext(), value);
			}
		}

	template <class T> void LinkedList<T>:: Print(LinkedListNode<T>* node)
		{
			/// Printing the linked list.
			if (node != nullptr)
			{
				std::cout << *node;
				Print(node->getNext());
			}
		}

	/// Operators overloading.---------------------------------------------------]

	template <class T> std::ostream& operator<<(std::ostream& out, LinkedList<T> list)
		{
			LinkedListNode<T>* tmp = list.getHead();
			while (tmp != nullptr)
			{
				out << *tmp;
				tmp = tmp->getNext();
			}
			return out;
		}
	
	/// END REGION--------------------------------------]
	// END: LinkedList<T>------------------------------------------------------------------------]

	// CLASS: StackNode<T>------------------------------------------------------------------------]
	/// Constructors ----------------------------------------------]
	template <class T> StackNode<T>::StackNode<T>(T value, StackNode<T>* next)
		{
			/// Create the stack node.
			this->value = value;
			this->next = next;
		}

	/// Destructors -----------------------------------------------]
	template <class T> StackNode<T>::~StackNode<T>()
		{
			/// Dispose resources.
			delete next;
		}

	/// Proporties -----------------------------------------------]
	template <class T> T StackNode<T>:: getValue()
		{
			/// Return value of the node.
			return value;
		}

	template <class T> void StackNode<T>:: setValue(T value)
		{
			/// Set the new value of the node.
			this->value = value;
		}

	template <class T> StackNode<T>* StackNode<T>:: getNext()
		{
			/// Return pointer to the next node.
			return next;
		}

	template <class T> void StackNode<T>::setNext(StackNode<T>* next)
		{
			/// Set the pointer to the next node.
			this->next = next;
		}

	/// Operators overloading ------------------------------------]

	/// Print the node.
	template <class T> std::ostream& operator<< (std::ostream& out, StackNode<T> node)
		{
			/// Output the value of the node.
			out << node.getValue();
			out << "\n";
			return out;
		}

	/// Are equals the nodes.
	template <class T> int operator== (StackNode<T> first, StackNode<T> second)
		{
			/// Compare two stack nodes.
			if (first.getValue() != second.getValue())
			{
				return 0;
			}
			return 1;
		}

	template <class T> int operator> (StackNode<T> first, StackNode<T> second)
		{
			/// Compare the stack nodes.
			if (first.getValue() > second.getValue())
			{
				return 1;
			}
			return 0;
		}
	// END: LinkedList<T>------------------------------------------------------------------------]

	// CLASS: Stack<T>------------------------------------------------------------------------]
	template<class T> Stack<T>::Stack<T>(T value)
		{
			/// Create the stack with start value.
			head = new StackNode<T>(value, nullptr);
			n = 1;
		}

	template<class T> Stack<T>::Stack<T>()
		{
			/// Default constructor.
			head = nullptr;
			n = 0;
		}

	/// Destructors-------------------------------------------]
	template<class T> Stack<T>::~Stack<T>()
		{
			/// Dispose resources.
			delete head;
		}

	/// Proporties --------------------------------------------]

	/// a) getters:

	template<class T> StackNode<T>* Stack<T>:: getHead()
		{
			/// Return head of the stack.
			return head;
		}

	template <class T> int Stack<T>:: getLength()
		{
			/// Return size of the stack.
			return n;
		}

	/// Methods ----------------------------------------------]

	template <class T> void Stack<T>:: Push(T value)
		{
			/// Push value on the stack.
			head = new StackNode<T>(value, head);
		}

	template <class T> T Stack<T>:: Pop()
		{
			/// Pop value from the stack.
			T tmp = head->getValue();
			head = head->getNext();
			return tmp;
		}

	template <class T> T Stack<T>:: Peek()
		{
			/// Peek the value on the stack.
			return head->getValue();
		}

	/// Operators overloading ---------------------------------]

	template <class T> std::ostream& operator<< (std::ostream& out, Stack<T> stack)
		{
			StackNode<T>* tmp = stack.getHead();
			while (tmp != nullptr)
			{
				out << *tmp;
				tmp = tmp->getNext();
			}
			return out;
		}
	// END CLASS: Stack<T>------------------------------------------------------------------------]

	// CLASS: List<T>------------------------------------------------------------------------]

	/// Constructors--------------------------------]
		
	template <class T> List<T>::List<T>(int size)
		{
			/// Constructing the list with given size.
			this->size = size;
			data = new T[size];
			n = 0;
		}

	template <class T> List<T>::List<T>()
		{
			/// Constructing the list with default size.
			this->size = 32;
			data = new T[size];
			n = 0;
		}

	template <class T> List<T>::List<T>(int size, T value)
		{
			/// Constructing the list with given size and value of the first element.
			this->size = size;
			data = new T[size];
			n = 0;
			data[n++] = value;
		}

	/// Dentructors---------------------------------]
	template <class T> List<T>::~List<T>()
		{
			/// Dispose resources.
			delete data;
		}

	/// Proporties----------------------------------]
	template <class T>int List<T>:: getCount()
		{
			/// Return the number of the elements.
			return n;
		}

	template <class T> T* List<T>:: getData()
		{
			/// Return to pointer do dynamically allocated data.
			return data;
		}

	/// Methods-------------------------------------]

	template <class T>void List<T>:: Add(T value)
		{
			/// Adding an element to the list.
			if (n > size)
			{
				Resize();
			}
			data[n++] = value;
		}

	template <class T> void List<T>:: Remove(T value)
		{
			/// Removing an element from the list.

			/// 1. Getting the index of the element.
			int index = getIndex(value);

			/// 2. If the element is on the list.
			if (index != -1)
			{
				/// 3. Shift the array with data to remove the value.
				ShiftDown(index);
			}
		}

	template <class T> void List<T>:: ShiftDown(int index)
		{
			/// Shift the data.
			int i = index + 1;
			while (i < n)
			{
				data[i - 1] = data[i];
				i++;
			}
			n--;
		}

	template<class T> int List<T>:: getIndex(T value)
		{
			/// Finding the index of the given value.
			for (int i = 0; i < n; i++)
			{
				if (data[i] == value)
				{
					/// If it's the value that we looking for, return index.
					return i;
				}
			}
			/// If value isn't on the list, return -1.
			return -1;
		}

	/// Helper methods----------------------]
	template <class T> void List<T>:: Resize()
		{
			size = size * 2;
			T* tmp = new T[size];
			for (int i = 0; i < n; i++)
			{
				tmp[i] = data[i];
			}
			data = tmp;
		}

	/// Operators overloading---------------]

	/// a) Printing.
	template <class T> std::ostream& operator<< (std::ostream& out, List<T> list)
		{
			T* tmp = list.getData();
			int n = list.getCount();
			for (int i = 0; i < n; i++)
			{
				out << tmp[i];
				out << std::endl;
			}
			return out;
		}

	// END : List<T>------------------------------------------------------------------------]

	// CLASS: QueueNode<T>------------------------------------------------------------------------]

	/// Constructors-------------------------]
	template <class T> QueueNode<T>::QueueNode<T>(T value, QueueNode<T>* next)
		{
			/// Create queue node.
			this->value = value;
			this->next = next;
		}

	template <class T> QueueNode<T>::QueueNode<T>(T value)
		{
			/// Create queue node without start reference to next node.
			this->value;
			next = nullptr;
		}
	/// Destructors--------------------------]
	template <class T> QueueNode<T>::~QueueNode<T>()
		{
			/// Remove from memory array with data.
			//delete next;
		}

	/// Proporties---------------------------]

	/// a) Getters.

	template <class T> T QueueNode<T>:: getValue()
		{
			/// Get the value of the node.
			return value;
		}

	template <class T> QueueNode<T>* QueueNode<T>:: getNext()
		{
			/// Get pointer to the next node.
			return next;
		}

	/// b) Setters.

	template <class T> void QueueNode<T>:: setValue(T value)
		{
			/// Set the value of the node.
			this->value = value;
		}

	template <class T> void QueueNode<T>:: setNext(QueueNode<T>* next)
		{
			/// Set pointer to next node.
			this->next = next;
		}

	/// Operators overloading---------------]

	/// a) Printing.

	template <class T> std::ostream& operator<< (std::ostream& out, QueueNode<T> node)
		{
			/// Outputing the value of the node.
			out << node.getValue();
			out << std::endl;
			return out;
		}

	/// b) Comparing.

	template <class T> int operator== (QueueNode<T> first, QueueNode<T> second)
		{
			/// Compare two linked list nodes.
			if (first.getValue() != second.getValue())
			{
				return 0;
			}
			return 1;
		}

	template <class T> int operator> (QueueNode<T> first, QueueNode<T> second)
		{
			/// Compare who is greater.
			if (first.getValue() > second.getValue())
			{
				return 1;
			}
			return 0;
		}

	// END: QueueNode<T>------------------------------------------------------------------------]

	// CLASS: Queue<T>------------------------------------------------------------------------]

	/// Constructors.----------------------------------------------]
	template <class T> Queue<T>::Queue<T>()
		{
			/// Create default queue.
			front = nullptr;
			back = nullptr;
			n = 0;
		}

	/// Destructors.-----------------------------------------------]
	template <class T> Queue<T>::~Queue<T>()
		{
			/// Dispose resources.
			delete front;
			delete back;
		}


	/// Proporties.------------------------------------------------]

	/// a) Getters.

	template <class T> QueueNode<T>* Queue<T>:: getFront()
		{
			/// Return pointer to the front of the queue.
			return front;
		}

	template <class T> QueueNode<T>* Queue<T>:: getBack()
		{
			/// Return pointer to the back of the queue.
			return back;
		}

	template <class T> int Queue<T>:: getCount()
		{
			/// Return length of the queue.
			return n;
		}

	/// Methods.---------------------------------------------------]

	template <class T> void Queue<T>:: Enqueue(T value)
		{
			/// Add element to the queue.
			if (front == nullptr)
			{
				front = new QueueNode<T>(value, back);
			}
			else if (front != nullptr && back == nullptr)
			{
				back = new QueueNode<T>(value, nullptr);
				front->setNext(back);
			}
			else
			{
				QueueNode<T>* tmp = new QueueNode<T>(value, nullptr);
				back->setNext(tmp);
				back = tmp;
			}
			n++;
		}

	template <class T> T Queue<T>::Dequeue()
		{
			/// Remove element from the queue.
			T tmp = front->getValue();
			front = front->getNext();
			n--;
			return tmp;
		}

	/// Operators overloading.---------------------------------------]

	/// a) Printing.

	template <class T> std::ostream& operator<< (std::ostream& out, Queue<T> queue)
		{
			QueueNode<T>* tmp;
			tmp = queue.getFront();
			while (tmp != nullptr)
			{
				out << *tmp;
				tmp = tmp->getNext();
			}
			return out;
		}

	// END: Queue<T>------------------------------------------------------------------------]

	// CLASS: BSTNode<T>------------------------------------------------------------------------]

	/// Constructors--------------------------------]
	template <class T> BSTNode<T>::BSTNode<T>(T value, BSTNode<T>* left, BSTNode<T>* right)
		{
			/// Create the BST node by given all arguments.
			this->value = value;
			this->left = left;
			this->right = right;
		}

	template <class T> BSTNode<T>::BSTNode<T>(T value)
		{
			/// Create the BST node using only value.
			this->value = value;
			left = nullptr;
			right = nullptr;
		}

	/// Proporties-----------------------------------]

	/// a) Getters.

	template <class T> T BSTNode<T>::getValue()
		{
			/// Return the value of the node.
			return value;
		}

	template <class T> BSTNode<T>* BSTNode<T>:: getLeft()
		{
			/// Return pointer to the left node.
			return left;
		}

	template <class T> BSTNode<T>* BSTNode<T>:: getRight()
		{
			/// Return poiner to the right node.
			return right;
		}

	/// b) Setters.

	template <class T> void  BSTNode<T>:: setValue(T value)
		{
			/// Set the new value of the node.
			this->value = value;
		}

	template <class T> void  BSTNode<T>::setLeft(BSTNode<T>* left)
		{
			/// Set the new address of the pointer to the left.
			this->left = left;
		}

	template <class T> void  BSTNode<T>::setRight(BSTNode<T>* right)
		{
			/// Set the new address of the pointer to the right.
			this->right = right;
		}

	/// Operators overloading-----------------------------------]

	/// Printing.

	template <class T> std::ostream& operator<< (std::ostream& out, BSTNode<T> node)
		{
			out << node.getValue();
			return out;
		}

	// KONIEC BST NODE

	// CLASS: BST<T>------------------------------------------------------------------------]

	/// Constructors.------------------------------]
	template <class T> BST<T>:: BST<T>(T value)
	{
		/// Create tree with given start value of the root.
		root = new BSTNode<T>(value);
		count = 1;
	}

	template <class T> BST<T>::BST<T>()
	{
		/// Create tree without given start value of the root.
		root = nullptr;
		count = 0;
	}

	/// Proporties. -------------------------------]

	/// a) Getters.

	template <class T> BSTNode<T>* BST<T>:: getRoot()
	{
		/// Return pointer to the root of the tree.
		return root;
	}

	template <class T> int BST<T>:: getCount()
	{
		/// Return size of the tree.
		return count;
	}

	/// Methods. -------------------------------]

	template <class T> void  BST<T>::Add(T value)
		{
			/// Add element to the binary search tree.
			if (root == nullptr)
			{
				root = new BSTNode<T>(value);
				count++;
			}
			else
			{
				Add(root, value);
			}
		}

	template <class T> void BST<T>::Print()
	{
		/// Print the tree.
		Print(root);
	}

	template <class T> void BST<T>::Add(BSTNode<T>* node, T value)
		{
			/// 1. New value is smaller than current value of the node <-> LEFT SIDE OF THE TREE.
			if (node->getValue() > value)
			{
				/// 2. If left pointer is null than create new left node.
				if (node->getLeft() == nullptr)
				{
					node->setLeft(new BSTNode<T>(value));
					count++;
				}
				else /// 2. Go down to the tree.
				{
					Add(node->getLeft(), value);
				}
			}
			/// 1. New value is bigger than current value of the node <-> RIGHT SIDE OF THE TREE.
			else if (node->getValue() < value)
			{
				/// 2. If there is no right node, create one.
				if (node->getRight() == nullptr)
				{
					node->setRight(new BSTNode<T>(value));
					count++;
				}
				else /// 2. Go down to the tree.
				{
					Add(node->getRight(), value);
				}
			}
		}

	template <class T> void BST<T>::Print(BSTNode<T>* node)
		{
			/// TODO: Print the values from the BST.

			/// 1. If current node is null, end.
			if (node == nullptr)
			{
				return;
			}

			/// 2. If left node is not null, go there.
			if (node->getLeft() != nullptr)
			{
				Print(node->getLeft());
			}

			/// 3. Print value of the current node.
			std::cout << *node;
			std::cout << std::endl;

			/// 4. If right node is not null, go there.
			if (node->getRight() != nullptr)
			{
				Print(node->getRight());
			}
		}

	/// Operators overloading. -------------------------------------]

	/// a) Printing.

	template <class T> std::ostream& operator<< (std::ostream& out, BST<T> bst)
		{
			bst.Print();
			return out;
		}

	// END: BST<T>------------------------------------------------------------------------]

	// CLASS: HeapNode<T>------------------------------------------------------------------------]

	/// Constructors---------------------------------]
	template <class T> HeapNode<T>::HeapNode<T>(T value, HeapNode<T>* left, HeapNode<T>* right)
		{
			/// Create the heap node with given all values.
			this->value = value;
			this->left = left;
			this->right;
		}

	template <class T> HeapNode<T>::HeapNode<T>(T value)
		{
			/// Creathe the heap node with only value.
			this->value = value;
			left = nullptr;
			right = nullptr;
		}

	/// Proporties-------------------------------------]

	/// a) Getters.

	template <class T> T HeapNode<T>:: getValue()
		{
			/// Return value of the node.
			return value;
		}

	template <class T> HeapNode<T>* HeapNode<T>:: getLeft()
		{
			/// Return pointer to the left child node.
			return left;
		}

	template <class T> HeapNode<T>* HeapNode<T>::getRight()
		{
			/// Return pointer to the right child node.
			return right;
		}

	/// b) Setters.

	template <class T> void HeapNode<T>::setValue(T value)
		{
			/// Set the value of the node.
			this->value = value;
		}

	template <class T> void HeapNode<T>::setLeft(HeapNode<T>* left)
		{
			/// Set a new pointer to left child node.
			this->left = left;
		}

	template <class T> void HeapNode<T>::setRight(HeapNode<T>* right)
		{
			/// Set a new pointer to right child node.
			this->right = right;
		}

	/// Operators Overloading--------------------------------]

	/// a) Printing.

	template <class T> std::ostream& operator<< (std::ostream& out, HeapNode<T> node)
		{
			/// Output the value of the node.
			out << node.getValue();
			return out;
		}

	// END: HeapNode<T>------------------------------------------------------------------------]

	// CLASS: Heap<T>------------------------------------------------------------------------]

	/// Constructors. ------------------------------]
	template <class T> Heap<T>::Heap<T>(T value)
		{
			/// Create with heap with given value.
			root = new HeapNode<T>(value);
			n = 1;
		}

	template <class T> Heap<T>::Heap<T>()
		{
			/// Create heap default fields.
			root = nullptr;
			n = 0;
		}

	/// Destructors.---------------------------------]
	template <class T> Heap<T>::~Heap<T>()
		{
			/// Create heap default fields.
			delete root;
			n = 0;
		}

	/// Proporties.----------------------------------]

	/// a) Getters.

	template <class T> HeapNode<T>* Heap<T>:: getRoot()
		{
			/// Return pointer to the root of heap.
			return root;
		}

	template <class T> int Heap<T>:: getCount()
		{
			/// Return number of elements in the heap.
			return n;
		}

	/// Methods.--------------------------------------]

	template <class T> void Heap<T>::Add(T value)
		{
			/// Add element to the heap.
			if (root == nullptr)
			{
				root = new HeapNode<T>(value);
			}
			else
			{
				Add(root, value);
			}
			n++;
		}

	template <class T> void Heap<T>:: Print()
		{
			/// Print heap.
			Print_InOrder(root);
		}

	template <class T> void Print_InOrder(HeapNode<T>* node)
		{
			/// Print in order the tree.
			if (node == nullptr)
			{
				return;
			}

			if (node->getLeft() != nullptr)
			{
				Print(node->getLeft());
			}

			std::cout << *node;
			std::cout << std::endl;

			if (node->getRight() != nullptr)
			{
				Print(node->getRight());
			}
		}

	template <class T> void Add(HeapNode<T>* node, T value)
		{
			/// Add element to the tree.
			if (node->getLeft() == nullptr)
			{
				node->setLeft(new HeapNode<T>(value));
			}
			else if (node->getRight() == nullptr)
			{
				node->setRight(new HeapNode<T>(value));
			}
			else
			{
				Add(node->getLeft(), value);
			}
		}

	/// Operators overloading.----------------------------------]

	/// a) Printing.

	template <class T> std::ostream& operator<< (std::ostream& out, Heap<T> heap)
		{
			heap.Print();
			return out;
		}
	// END: Heap<T>------------------------------------------------------------------------]
};

namespace SA
{
	/// REGION: Sorting algorithms.---------------------]

	// SelectionSort----------------------------------------------------------------]

	template <class T> void SelectionSort<T>::Sort(T* data, int size)
		{
			for (int i = 0; i < size; i++)
			{
				// 1. Get current position in the table.
				int current = i;

				// 2. Get the value of the current position.
				T current_value = data[current];

				// 3. Go through the rest of the table.
				for (int j = i; j < size; j++)
				{
					// 4. If it's max, save the index of it.
					if (current_value > data[j])
					{
						current_value = data[j];
						current = j;
					}
				}

				// 5. Swap the finded maximum value with current value.
				T tmp = data[i];
				data[i] = data[current];
				data[current] = tmp;
			}
		}

	//------------------------------------------------------------------------------]

	// BubbleSort-------------------------------------------------------------------]
	
	template <class T> void BubbleSort<T>::Sort(T* data, int size)
		{
			/// 1. Go through the array.
			for (int i = 0; i < size; i++)
			{
				/// 2. Go through the array.
				for (int j = 1; j < size; j++)
				{
					/// 3. Check if current position is bigger than next position, if it's swap.
					if (data[j - 1] > data[j])
					{
						T tmp = data[j - 1];
						data[j - 1] = data[j];
						data[j] = tmp;
					}
				}
			}
		}

	//------------------------------------------------------------------------------]

	// GnomeSort--------------------------------------------------------------------]

	template <class T> void GnomeSort<T>::Sort(T* data, int size)
		{
			/// 1. Set current position of the gnome to be 1.
			int cr = 1;
			while (cr < size)
			{
				/// 2.1 Check if the previus neighbour is bigger:
				/// - If it's then swap and go to the previous location.
				if ((cr - 1) != -1 && data[cr - 1] > data[cr])
				{
					T tmp = data[cr - 1];
					data[cr - 1] = data[cr];
					data[cr] = tmp;
					cr--;
				}
				/// 2.2 If it's not bigger, than go forward.
				else
				{
					cr++;
				}
			}
			/// 3. Gnome has reached the end of the array.
		}

	//------------------------------------------------------------------------------]

	// InsertionSort----------------------------------------------------------------]

	template <class T> void InsertionSort<T>::Sort(T* data, int size)
		{
			for (int i = 0; i < size; i++)
			{
				/// 1. Get barrier.
				int j = i;
				while (j > 0)
				{
					/// 2. If previous is bigger than current, change it.
					if (j != 0 && data[j] < data[j - 1])
					{
						T tmp = data[j];
						data[j] = data[j - 1];
						data[j - 1] = tmp;
					}
					j--;
				}
			}
		}

	//------------------------------------------------------------------------------]

	// ShellSort--------------------------------------------------------------------]

	template <class T> void ShellSort<T>::Sort(T* array, int n)
		{
			int distance = n / 2;
			while (distance >= 1)
			{
				int j = distance;
				while (j < n)
				{
					int i = j - distance;
					while (i >= 0)
					{
						if (array[i + distance] > array[i])
						{
							break;
						}
						else
						{
							T tmp = array[i + distance];
							array[i + distance] = array[i];
							array[i] = tmp;
							i -= distance;
						}
					}
					j++;
				}
				distance /= 2;
			}
		}

	//------------------------------------------------------------------------------]

	// GnomeSort--------------------------------------------------------------------]

	template <class T> void QuickSort<T>::Sort(T* array, int n)
		{
			Sort(array, 0, n - 1);
		}

	template <class T> void QuickSort<T>::Sort(T* array, int lower, int upper)
		{
			if (lower < upper)
			{
				int p = Partition(array, lower, upper);
				Sort(array, lower, p);
				Sort(array, p + 1, upper);
			}
		}
	
	template <class T> int QuickSort<T>::Partition(T* array, int lower, int upper)
		{
			int i = lower;
			int j = upper;
			T pivot = array[i];
			do
			{
				while (array[i] < pivot)
				{
					i++;
				}
				while (array[j] > pivot)
				{
					j--;
				}
				if (i >= j)
				{
					break;
				}
				else
				{
					T tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;
				}

			} while (i <= j);
			return j;
		}

	// QuickSort--------------------------------------------------------------------]

	// MergeSort--------------------------------------------------------------------]

	template <class T> void MergeSort<T>::Sort(T* array, int n)
	{
		MergeSort<T>::Sort(array, 0, n - 1, n);
	}

	template <class T> void MergeSort<T>:: Sort(T* array, int lower, int upper, int n)
	{
		if (lower < upper)
			{
				int middle = (lower + upper) / 2;
				Sort(array, lower, middle, n);
				Sort(array, middle + 1, upper, n);
				Merge(array, lower, middle, upper, n);
			}
	}

	template <class T> void MergeSort<T>::Merge(T* array, int lower, int middle, int upper, int n)
		{
			int i = lower;
			int j = middle + 1;

			T* tmp = new T[n];
			int k = lower;

			while (i <= middle && j <= upper)
			{
				if (array[i] < array[j])
				{
					tmp[k] = array[i];
					i++;
				}
				else
				{
					tmp[k] = array[j];
					j++;
				}
				k++;
			}

			if (i > middle)
			{
				while (j <= upper)
				{
					tmp[k] = array[j];
					j++;
					k++;
				}
			}
			else
			{
				while (i <= middle)
				{
					tmp[k] = array[i];
					i++;
					k++;
				}
			}

			for (int x = lower; x <= upper; x++)
			{
				array[x] = tmp[x];
			}
		}
	
	//------------------------------------------------------------------------------]
}
