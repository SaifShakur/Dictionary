//Saif Shakur

//***#include<iostream>***: Included for the optional functions "showtree" and "GetTree"
#include "Dictionary.h"

//---|-------------------------------------------------------------------|---
//---|---implementation of "node" class functions/overloaded operators---|---
//---|-------------------------------------------------------------------|---

//Default constructor
template<typename KeyType,typename ItemType>
node<KeyType, ItemType>::node(){

	left = nullptr;
	right = nullptr;
}

//-----Custom constructors
template<typename KeyType,typename ItemType>
node<KeyType, ItemType>::node(const KeyType& newkey){

	key = newkey;
	left = nullptr;
	right = nullptr;
}
//-----'''''''''''''''''''
template<typename KeyType,typename ItemType>
node<KeyType, ItemType>::node(const KeyType& newkey, const ItemType& newitem){

	key = newkey;
	item = newitem;
	left = nullptr;
	right = nullptr;
}

//Copy Constructor
template<typename KeyType,typename ItemType>
node<KeyType, ItemType>::node(const node& rhs){

	key = rhs.get_key();
	item = rhs.get_item();

	left = rhs.get_left();
	right = rhs.get_right();
}

//Copy Assignment Operator
template<typename KeyType,typename ItemType>
node<KeyType, ItemType>& node<KeyType, ItemType>::operator =(const node& rhs){

	key = rhs.get_key();
	item = rhs.get_item();

	left = rhs.get_left();
	right = rhs.get_right();
	
	return *this;
}

//Move Constructor
template<typename KeyType,typename ItemType>
node<KeyType, ItemType>::node(node&& rhs){

	key = rhs.get_key();
	item = rhs.get_item();

	left = rhs.get_left();
	right = rhs.get_right();

	rhs.set_left(nullptr);
	rhs.set_right(nullptr);
}

//Move Assignment Operator
template<typename KeyType,typename ItemType>
node<KeyType, ItemType>& node<KeyType, ItemType>::operator = (node&& rhs){

	key = rhs.get_key();
	item = rhs.get_item();

	left = rhs.get_left();
	right = rhs.get_right();

	rhs.set_left(nullptr);
	rhs.set_right(nullptr);
	
	return *this;
}

//Deconstructor
template<typename KeyType,typename ItemType> 
node<KeyType, ItemType>::~node(){ 

	left = nullptr;
	right = nullptr; 
}


//Accessor and mutator functions for "key" data type
template<typename KeyType,typename ItemType>
void node<KeyType, ItemType>::set_key(const KeyType& newkey){key = newkey;}

template<typename KeyType,typename ItemType>
KeyType node<KeyType, ItemType>::get_key() const{return key;}

//' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' "item" data type
template<typename KeyType,typename ItemType>
void node<KeyType, ItemType>::set_item(const ItemType& newitem){item = newitem;}

template<typename KeyType,typename ItemType>
ItemType node<KeyType, ItemType>::get_item() const {return item;}

template<typename KeyType,typename ItemType>
ItemType& node<KeyType, ItemType>::ref_item(){return item;};    

//' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' 'left node
template<typename KeyType,typename ItemType>
void node<KeyType, ItemType>::set_left(node<KeyType, ItemType>* newnode){left = newnode;}

template<typename KeyType,typename ItemType>
node<KeyType, ItemType>* node<KeyType, ItemType>::get_left() const{return left;}

//' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' right node
template<typename KeyType,typename ItemType>
void node<KeyType, ItemType>::set_right(node<KeyType, ItemType>* newnode){right = newnode;}

template<typename KeyType,typename ItemType>
node<KeyType, ItemType>* node<KeyType, ItemType>::get_right() const{return right;};

//operator overload for the key values with: ==
template<typename KeyType,typename ItemType>
bool node<KeyType, ItemType>::operator == (const KeyType& otherkey){
    
    if(key == otherkey)
        return true;
    else
        return false;
}

//' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' '  !=
template<typename KeyType,typename ItemType>
bool node<KeyType, ItemType>::operator != (const KeyType& otherkey){

    if(key != otherkey)
        return true;
    else
        return false;
}

//' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' '  >
template<typename KeyType,typename ItemType>
bool node<KeyType, ItemType>::operator > (const KeyType& otherkey){

    if(key > otherkey)
        return true;
    else
        return false;
}

//' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' '  <
template<typename KeyType,typename ItemType>
bool node<KeyType, ItemType>::operator < (const KeyType& otherkey){

    if(key < otherkey)
        return true;
    else
        return false;
}

//' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' '  >=
template<typename KeyType,typename ItemType>
bool node<KeyType, ItemType>::operator >= (const KeyType& otherkey){

    if(key >= otherkey)
        return true;
    else
        return false;
}

//' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' '  <=
template<typename KeyType,typename ItemType>
bool node<KeyType, ItemType>::operator <= (const KeyType& otherkey){

    if(key <= otherkey)
        return true;
    else
        return false;
}

//---|---------------------------------------------------------------------|---
//---|-implementation of "Dictionary" class functions/overloaded operators-|---
//---|---------------------------------------------------------------------|---

//Default constructor
template<typename KeyType,typename ItemType>
Dictionary<KeyType, ItemType>::Dictionary(){
 
	root = nullptr;
	size = 0;
}

//Deconstructor
//Calls Clear();
template<typename KeyType,typename ItemType>
Dictionary<KeyType, ItemType>::~Dictionary(){ Clear(); }

//Checks if the tree is empty
template<typename KeyType,typename ItemType>
bool Dictionary<KeyType, ItemType>::IsEmpty(){
    
	if(root == nullptr)
		return true;
	else
		return false;
}

//Clears the container. Calls subclear(root)
template<typename KeyType,typename ItemType>
void Dictionary<KeyType, ItemType>::Clear(){
 
	subclear(root);
	root = nullptr;
}

//Returns a const of the "Size" variable 
template<typename KeyType,typename ItemType>
int Dictionary<KeyType, ItemType>::Size() const{ return size; }

//Returns the height of the tree. Calls getHeight(root)
template<typename KeyType,typename ItemType>
int Dictionary<KeyType, ItemType>::Height(){ 
	
	if(root == nullptr)
		return 0;
	else
		return (getHeight(root) - 1);
}

//Returns 1 if an item with a given key exists in the container and 0 otherwise.
template<typename KeyType,typename ItemType>
int Dictionary<KeyType, ItemType>::Count(const KeyType& findkey){

	node<KeyType, ItemType>* searching = root;

	while(searching != nullptr){
	    
		if(searching->get_key() == findkey)
			return 1;

		if(searching->get_key() > findkey)
			searching = searching -> get_left();
		else
			searching = searching -> get_right();
	}

	return 0;
}

//Operator [] overloaded
//Returns reference of the item in the node with the key "findkey." If a node with that key does not exist, then node is created.
template<typename KeyType,typename ItemType>
ItemType& Dictionary<KeyType, ItemType>::operator [](const KeyType& findkey){

	node<KeyType, ItemType>* nodewithkey = findnode(findkey);
	return nodewithkey->ref_item();
}

//Balances the BST. Calls: Trav_in_order(...), Clear(), subbalance(...)
template<typename KeyType,typename ItemType>
void Dictionary<KeyType, ItemType>::Balance(){

	int i = 0;
	int arraysize = size;

	node<KeyType, ItemType>* arrayofnodes = new node<KeyType, ItemType>[arraysize];
	//An array of nodes we will fill in order with the nodes in the BST

	Trav_in_order(arrayofnodes, root, i);			//Fills the array with the nodes from the "root"

	Clear();                			 	//Empties the current tree
	
	root = subbalance(arrayofnodes, 0, arraysize - 1);    	//Makes the root equal to the new tree
	
	delete []arrayofnodes;					//Deletes our temporary array
}

//Removes a node with a specific key. Calls: findPrevRemoveNode(...),findRemovenode(...), GetLeftBiggest(...);
template<typename KeyType,typename ItemType>
void Dictionary<KeyType, ItemType>::Remove(const KeyType& key2del){

	int found = Count(key2del);
	if(found == 0)	//If the node is not found within the tree, we exit
		return;
	
	//Pointer to the node that comes before the node we want to delete (In-Order wise)
	node<KeyType, ItemType>* prev;	
	node<KeyType, ItemType>* node2del = findRemovenode(key2del, prev);
	

	//Case 1: 0 children
	if((node2del->get_left() == nullptr) && (node2del->get_right() == nullptr)){
	
		delete node2del;
	
		prev->set_left(nullptr);
		size--;
		return;
	}

	//Case 2: 1 child
	if( ((node2del->get_left() == nullptr) && (node2del->get_right() != nullptr)) || (( node2del->get_right() == nullptr) && (node2del->get_left() != nullptr)) ){
		
		node<KeyType, ItemType>* temp;

		//The left child in node2del is the only child
		if( ((node2del->get_right() == nullptr) && (node2del->get_left() != nullptr)) ){

			temp = node2del;

			//Checking if the node we need to delete is to the left or to the right of the “prev” node
			if(prev->get_left() == node2del)
				prev->set_left(node2del->get_left());
			else if(prev->get_right() == node2del)
				prev->set_right(node2del->get_left());

			delete temp;
			node2del = nullptr;

			size--;
			
			return;
		}

		//The right child in node2del is the only child
		if( ((node2del->get_left() == nullptr) && (node2del->get_right() != nullptr)) ){

			temp = node2del;

			//Checking if the node we need to delete is to the left or to the right of the “prev” node
			if(prev->get_left() == node2del)
				prev->set_left(node2del->get_right());
			else if (prev->get_right() == node2del)
				prev->set_right(node2del->get_right());

			delete temp;
			node2del = nullptr;

			size--; 
			return;
		}
	}

	//Case 3: 2 Children
	if((node2del->get_left() != nullptr) && (node2del->get_right() != nullptr)){

		//The previous node of the LeftBiggest (PrevOfLeftBiggest).
		node<KeyType, ItemType>* PrevOfLeftBiggest;
		//Finding the biggest node in the left subtree of the node2del
		node<KeyType, ItemType>* LeftBiggest = GetLeftBiggest(node2del, PrevOfLeftBiggest);
		node<KeyType, ItemType>* temp;

		//***Special case*** The (LeftBiggest) is the node immediately to the left of the node2del
		
		if(node2del->get_left() == LeftBiggest){

			swap(node2del, LeftBiggest);

			temp = LeftBiggest;

			node2del->set_left(LeftBiggest->get_left());	

			delete temp;
			node2del = nullptr;

			size--;
			return;
		}

		//Swap contents of the (node2del) and the (LeftBiggest).
		swap(node2del, LeftBiggest);
			
		//Determining whether the LeftBiggest has 0 or 1 child
		//Case 3.1: Zero Children
		if((LeftBiggest->get_left() == nullptr) && (LeftBiggest->get_right() == nullptr)){
	
			delete LeftBiggest;
			node2del = nullptr;
	
			size--;
			return;
		}
	
		//Case 3.2: 1 child
		if( ((LeftBiggest->get_right() == nullptr) && (LeftBiggest->get_left() != nullptr)) ){
	
			temp = LeftBiggest;
			PrevOfLeftBiggest->set_right(LeftBiggest->get_left());

			delete temp;
			node2del = nullptr;

			size--;
			return;
		}	
	}
}
//---|-------------------------------------------------------------------|---
//---|-----------Utlity functions for "Dictionary" container-------------|---
//---|-------------------------------------------------------------------|---

//Clear();
//Clears the container recursively by implementing a post-order traversal of the BST
template<typename KeyType,typename ItemType>
void Dictionary<KeyType, ItemType>::subclear(node<KeyType, ItemType>* cur){

    if(cur == nullptr) return;

    subclear(cur->get_left());
    subclear(cur->get_right());
    delete cur;
	cur = nullptr;

	size--;	
}

//Height();
//Calculates the height of the tree by using recursion.
template<typename KeyType,typename ItemType>
int Dictionary<KeyType, ItemType>::getHeight(node<KeyType, ItemType>* node){

	if (node == nullptr)
		return 0;
	else
	{
		int lefttreeheight = getHeight( node->get_left() );
		int righttreeheight = getHeight( node->get_right() );

		if (lefttreeheight > righttreeheight) 
			return (lefttreeheight + 1 );
		else
			return(righttreeheight + 1);
   	}
}

//Operator[]
//Searches for the node with the "key2find" within the tree by starting from the root
//If node is not found, then we add it to the BST (addnode)
template<typename KeyType,typename ItemType>
node<KeyType, ItemType>* Dictionary<KeyType, ItemType>::findnode(const KeyType& key2find){

	bool found = false;				//flag to indicate if we found the value or not
	node<KeyType, ItemType>* searching = root;	//Starting from the root

	while(searching != nullptr){	
	    
		if(searching->get_key() == key2find){	//Comparing the key2find to the value of the key we're looking at. If
			    				//	it's not equal to the key we're looking at, we search the left
			found = true;    		//	or right subtree depending on the comparison result.
			return searching;
		}

		if(searching->get_key() > key2find) 	
			searching = searching->get_left();
		else
			searching = searching->get_right();
	}

	if(found == false){				//If the node has not been found in the tree, we create a new node
							//	and assign the "key2find" value to it.
		addnode(key2find);
		return findnode(key2find);
	}
}

//Operator[]
//Adds a node to the tree with the "addthiskey" value
template<typename KeyType,typename ItemType>
void Dictionary<KeyType, ItemType>::addnode(const KeyType& addthiskey){

	node<KeyType, ItemType>* traverse = root;		//Temp node to travese through the tree
	if(root == nullptr){					//If the tree is empty, create the new node with the "addthiskey"
		
		root = new node<KeyType, ItemType>(addthiskey);
		size++;
		return;
	}
	    
	while(traverse != nullptr){
	    
		if(traverse->get_key() > addthiskey){		//Go to left subtree if "addthiskey" is less than current key
			    
			if(traverse->get_left() != nullptr)	
				traverse = traverse->get_left();
			else{					//Setting left node of traverse node to "addthiskey"
				traverse->set_left(new node<KeyType, ItemType>(addthiskey));
				size++;
				return;
			}
		}

		if(traverse->get_key() < addthiskey){		//Go to right subtree if "addthiskey" is greater than current key
			    	
			if(traverse->get_right() != nullptr) 
				traverse = traverse->get_right();
			else{					//Setting right node of traverse node to "addthiskey"
				traverse->set_right(new node<KeyType, ItemType>(addthiskey));
				size++;
				return;
			}
		}
	}
}

//Balance();
//Fills "arrayofnodes" with the nodes in the BST using In-Order traversal recursion
template<typename KeyType,typename ItemType>
void Dictionary<KeyType, ItemType>::Trav_in_order(node<KeyType, ItemType>* arrayofnodes, node<KeyType, ItemType>* cur, int& i){
    
	if(cur == nullptr)	//Base Case
		return;

	Trav_in_order(arrayofnodes, cur->get_left(), i);	//Recursion

	arrayofnodes[i].set_item(cur->get_item());		//Fills the array at position "i" with the in-order node
	arrayofnodes[i].set_key(cur->get_key());
	i++;                    

	Trav_in_order(arrayofnodes, cur->get_right(), i);	//Recursion
	
	return;
}

//Balance();
//Returns a balanced tree created from the "arrayofnodes"
template<typename KeyType,typename ItemType>
node<KeyType, ItemType>* Dictionary<KeyType, ItemType>::subbalance(const node<KeyType, ItemType>* arrayofnodes, int small, int large){
    
	if(small > large) 
		return nullptr;

	int half = ((small + large)/2);

	//newnode is set to the halved node in the "arrayofnodes"
	node<KeyType, ItemType>* newnode = new node<KeyType, ItemType>(arrayofnodes[half].get_key(), arrayofnodes[half].get_item() ); 
	size++;

	newnode->set_left(subbalance(arrayofnodes, small, (half - 1)));		//Calls recursion to set the rest of the tree
	newnode->set_right(subbalance(arrayofnodes, (half + 1), large));
	    
	return newnode;		//Returns the newnode (the root)
}

//Remove(...);
//Used to find the previous in-order node to "key2find" and find the previous node of "key2find"
//	so we are able to reattach pointers
template<typename KeyType,typename ItemType>
node<KeyType, ItemType>* Dictionary<KeyType, ItemType>::findRemovenode(const KeyType& key2find, node<KeyType, ItemType>*& prev){

	node<KeyType, ItemType>* searching = root;
	prev = searching;

	if(root == nullptr) 
		return nullptr;

	while(searching != nullptr){
    
		if(searching->get_key() == key2find)
			return searching;
		if(searching->get_key() > key2find){
			
			prev = searching;
			searching = searching->get_left();
		}
        	else{
			prev = searching;
			searching = searching->get_right();
		}
	}	
}

//Remove(...)
//Finds the biggest node in the right subtree of the node left of "node2del"
template<typename KeyType, typename ItemType>
node<KeyType, ItemType>* Dictionary<KeyType, ItemType>::GetLeftBiggest(node<KeyType, ItemType>* node2del, node<KeyType, ItemType>*& PrevOfLeftBiggest){
	
	node<KeyType, ItemType>* searching = node2del->get_left();
	PrevOfLeftBiggest = searching;
	
	while(searching->get_right() != nullptr){

		PrevOfLeftBiggest = searching;
		searching = searching->get_right();
	}

	return searching;
}

//Swaps the key and item values between "node2del" and "leftbiggest"
template<typename KeyType, typename ItemType>
void Dictionary<KeyType, ItemType>::swap(node<KeyType, ItemType>* node2del, node<KeyType, ItemType>* leftbiggest){

	node<KeyType, ItemType> temp;

	temp.set_key(node2del->get_key());
	temp.set_item(node2del->get_item());

	node2del->set_key(leftbiggest->get_key());
	node2del->set_item(leftbiggest->get_item());

	leftbiggest->set_key(temp.get_key());
	leftbiggest->set_item(temp.get_item());
}

/*
template<typename KeyType, typename ItemType>
void Dictionary<KeyType, ItemType>::GetTree(){  

	if(root == nullptr){
		std::cout << "The Tree is Empty with NO root." << std::endl;
		return;
	}
	int i = 1;		
	bool hitroot = false;
	showtree(root, i, hitroot, root);
}

template<typename KeyType,typename ItemType>
void Dictionary<KeyType, ItemType>::showtree(node<KeyType, ItemType>* cur, int& number, bool direction, node<KeyType, ItemType>* prev){

	
 	 if(cur == nullptr) 
		return;

  	  showtree(cur->get_left(), number, false, cur);

    	std::cout << "In-Order Node " << number << ": Key = " << cur->get_key() << " | Item = " << cur->get_item() << std::endl;

	if(cur == root)
		std::cout << "	Root" << std::endl;
	else{
		if(direction == false)
			std::cout << "Left of " << prev->get_key() << std::endl;
		if(direction == true)
			std::cout << "		Right of " << prev->get_key() << std::endl;
	}

	
		
	number++;                    

   	showtree(cur->get_right(), number, true, cur);
}
*/

//What I used to compile/test in termianl on an Ubuntu OS: g++  -std=c++11  driver.cpp  Dictionary.h  -o  a.out
