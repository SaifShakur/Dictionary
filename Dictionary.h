//Saif Shakur

#ifndef DICTIONARY_H
#define DICTIONARY_H

//Declaration for the "node" class that serve as the objects in the Dictionary container
template<typename KeyType,typename ItemType>
class node{

	public:
		//Default constructor
		node();

		//Custom constructors
		node(const KeyType& newkey);
		node(const KeyType& newkey, const ItemType& newitem);
		
		//Big 5
		node(const node&);		//Copy constructor
		node& operator = (const node&);	//Copy assignment operator
		node (node&&);			//Move constructor
		node& operator = (node&&);	//Move assignment operator
		~node();			//Deconstructor

		//Accessor and mutator functions for "key"
		void set_key(const KeyType& newkey); 
		KeyType get_key() const;

		//Accessor and mutator functions for "item"
		void set_item(const ItemType& newitem);
		ItemType get_item() const;
		ItemType& ref_item();	
	
		//Accessor and mutator for the left node
		void set_left(node<KeyType, ItemType>* newnode);
		node<KeyType, ItemType>* get_left() const;

		//Accessor and mutator for the right node
		void set_right(node<KeyType, ItemType>* newnode);
		node<KeyType, ItemType>* get_right() const;

		//Comparison operator overloads
		bool operator == (const KeyType& otherkey);
		bool operator != (const KeyType& otherkey);
		bool operator > (const KeyType& otherkey);
		bool operator < (const KeyType& otherkey);
		bool operator >= (const KeyType& otherkey);
		bool operator <= (const KeyType& otherkey);
	
	private:
		KeyType key;	//The "key" data type
		ItemType item;	//The "item" data type
		node<KeyType, ItemType> *left, *right;	
		//the two pointers of the node (so we may implement the Binary Search Tree searching algorithm)
};

//Declartion of the Dictionary container template
template<typename KeyType,typename ItemType>
class Dictionary{

	public:

		//Constructor
		Dictionary();	

		//Deconstructor
		~Dictionary();	

		//Returns true if the container is empty.
		bool IsEmpty(); 

		//Removes all items and leaves the container empty.
		void Clear();	

		//Returns the number of items stored in the container.
		int Size() const;	

		//Returns the height of the binary search tree.
		int Height();

		//Returns 1 if an item with a given key exists in the container and 0 otherwise.
		int Count(const KeyType&);	

		//Returns the reference to the item with the given key. 
		ItemType& operator[](const KeyType&);	
	
		//Removes the item with the specified key from the container.
		void Remove(const KeyType&);	

		//Rearranges the tree to make it balanced.
		void Balance();	

		//***void GetTree();  //Function to output tree to user for readability/trouble shooting.

	private:
		int size;			//Size of container
		node<KeyType, ItemType>* root;	//Root of the BST

		//----------UTILITY FUNCTIONS BELOW----------
		//Clear()
		void subclear(node<KeyType, ItemType>* );		

		//Height()
		int getHeight(node<KeyType, ItemType>* );	

		//Operator[]
		node<KeyType, ItemType>* findnode (const KeyType& );
		void addnode(const KeyType& );				

		//Balance()
		void Trav_in_order(node<KeyType, ItemType>*, node<KeyType, ItemType>*, int&);	
		node<KeyType, ItemType>* subbalance(const node<KeyType, ItemType>*, int small, int large);

		//Remove()
		node<KeyType, ItemType>* findRemovenode(const KeyType&, node<KeyType, ItemType>*&);	
		node<KeyType, ItemType>* GetLeftBiggest(node<KeyType, ItemType>*, node<KeyType, ItemType>*&);	

		//Swap the contents of the two nodes 
		void swap(node<KeyType, ItemType>*, node<KeyType, ItemType>*);

		//***Used in GetTree();***
		//***void showtree(node<KeyType, ItemType>* , int&, bool, node<KeyType, ItemType>*);
};

#include "Dictionary.cpp"
#endif
