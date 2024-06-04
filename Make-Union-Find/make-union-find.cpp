/*
MUF: Vanilla (No Optimization)
Make: O(1)
Find: O(1)
Union: O(n)

Cost of m operations MUF, of which n are Make operations: O(m+n^2)
--------------------------------------------------------------------
*/
#include<iostream>
#include<string>

using namespace std;

struct Set{
	int key;
	struct Set *next;
	struct Set *rep;
	struct Set *last;
	
};
typedef struct Set set;

set* Make(int str){
	set *s = new set();
	s->key = str;
	s->next = nullptr;
	s->rep = s;
	s->last = s;
	return s;
}

set* Find(set* x){
	return x->rep;
}

void Link(set* s_x, set* s_y){
	s_x->last->next = s_y;
	set* cur = s_y;
	while(cur != nullptr){
		s_y->rep = s_x;
		cur = cur->next;
	}
	s_x->last = s_y->last;
	
}

void Union(set* x, set* y){
	set* s_x = Find(x);
	set* s_y = Find(y);
	if(s_x != s_y){
		Link(s_x, s_y);
	}
}

void printSet(set* x){
	set* cur = Find(x);
	while(cur != nullptr){
		cout << cur->key << endl;
		cur = cur->next;
	}
}
//----------------------------------------------------------------------------
/*
MUF: Union by Rank (Optimization)
Make: O(1)
Find: O(h)
Union: O(h)

Cost of m operations MUF, of which n are Make operations: O(m*F(m,n)).
F(m,n), is the inverse of the function of ackermann, it grows very slowly, slower than logarithms
----------------------------------------------------------------------------
*/
struct Set_U{
	int key;
	struct Set_U *parent;
	int rank;
	
};
typedef struct Set_U set_u;

set_u* Make_rank(int x){
	set_u *s = new set_u();
	s->key = x;
	s->parent = s;
	s->rank = 0;
	return s;
}

set_u* Find_rank(set_u* x){
	set_u* cur = x;
	while(cur->parent != cur){
		cur  = cur->parent;
	}
	return cur;
}

void Link_rank(set_u* tree_x, set_u* tree_y){
	tree_y->parent =tree_x;
	return;
}

void Union_rank(set_u* x, set_u* y){
	set_u* tree_x = Find_rank(x);
	set_u* tree_y = Find_rank(y);
	if(tree_x != tree_y){
		if(tree_x->rank > tree_y->rank){
			Link_rank(tree_x, tree_y);
		}else{
			Link_rank(tree_y, tree_x);
			if(tree_x->rank == tree_y->rank){
				tree_y->rank = tree_y->rank + 1;
			}
		}
	}
	return;
}

//----------------------------------------------------------------------------
int main(){
	set_u* s1 = Make_rank(1);
	set_u* s2 = Make_rank(2);
	set_u* s3 = Make_rank(3);
	set_u* s4 = Make_rank(4);
	Union_rank(s1, s2);
	Union_rank(s3, s4);
	Union_rank(s1, s3);
	return 0;
}