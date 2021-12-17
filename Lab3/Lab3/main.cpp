#include "binarySearchTree.h"
using namespace std;

int main()
{
	try{
		BinarySearchTree Tree;
		Tree.insert(77);
		Tree.insert(31);
		Tree.insert(123);
		Tree.insert(23);
	    Tree.insert(56);
		Tree.insert(123);
		Tree.insert(934);

		cout << "Depth-first traverse:\n";
		BinarySearchTree::Iterator* D = Tree.create_dft_iterator();
		while (D->hasNext()) {
			cout<< D->next() << " ";
		}

		cout << "\n\nBreadth-first traverse:\n";
		BinarySearchTree::Iterator* B = Tree.create_bft_iterator();
		while (B->hasNext2()){
			cout << B->Next2() << " ";
		}
	}
	catch (exception ex) { cout << endl << ex.what(); }
	_getch();
}