// ���������������� ������� ������.
// ������������ � �������������� ������������� ������.
#pragma once
#ifndef _AVL_GUS_BALANCED_TREE_CPP_
#define _AVL_GUS_BALANCED_TREE_CPP_ 1

// ��� ��� ������
// ������ ��� ������ � ������������� ������ 
// ������������ � ����������� ��������� ��������� 
// ����� ���������� ��� ����������� ��������� ������.

// ��� ������ ��� ��������� ������ ����������� ����������� ��� 
// �������� �� log_2 (number of neighbour count) ��������. 

// �.�. ��������-�������� � �.�. ������ 1962 (����� �� ������ ������� ������ ����.).
// ���� � ������������ ��������� ����� ������� ������.


// Gus - ���� ��������� IBM 1978.


//��������� ������� ������ � insert � remove

// ���� ��� ������.
struct node_AVL_Gus
{
	integer key;
	// ������ ��������� � ������ � ������ ����.
	unsigned char height;
	node_AVL_Gus* left = nullptr;
	node_AVL_Gus* right = nullptr;
	// �����������.
	node_AVL_Gus(integer k) { key = k; left = right = 0; height = 1; }
};


// �������� ����� � � ������� ���������.
// ������ ���� height
unsigned char height_Gus(node_AVL_Gus* p)
{
	return p ? p->height : 0;
};

// ��������� balance factor ��������� ����
// �������� ������ � ���������� �����������.
integer bfactor_Gus(node_AVL_Gus* p)
{
	return height_Gus(p->right) - height_Gus(p->left);
};

// ��������������� ���������� �������� ���� height
// ��������� ���� (��� �������, ��� �������� ����� ���� 
// � ������ � ����� �������� ����� �������� �����������).
void fixheight_Gus(node_AVL_Gus* p)
{
	unsigned char hl = height_Gus(p->left);
	unsigned char hr = height_Gus(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
};

// ������������ �����.
node_AVL_Gus* rotateright_Gus(node_AVL_Gus* p)
{
	// ������ ������� ������ p
	node_AVL_Gus* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight_Gus(p);
	fixheight_Gus(q);
	return q;
};

// ����� ������� �������� ������������ ������ �������:
node_AVL_Gus* rotateleft_Gus(node_AVL_Gus* q)
{
	// ����� ������� ������ q
	node_AVL_Gus* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight_Gus(q);
	fixheight_Gus(p);
	return p;
};

// ��� ����������� ������������ �������� � �������� ������� � ���������� ���������
node_AVL_Gus* balance_Gus(node_AVL_Gus* p) // ������������ ���� p
{
	fixheight_Gus(p);
	if (bfactor_Gus(p) == 2)
	{
		if (bfactor_Gus(p->right) < 0)
			p->right = rotateright_Gus(p->right);
		return rotateleft_Gus(p);
	}
	if (bfactor_Gus(p) == -2)
	{
		if (bfactor_Gus(p->left) > 0)
			p->left = rotateleft_Gus(p->left);
		return rotateright_Gus(p);
	}
	return p; // ������������ �� �����
}

// ������� ������ � ������.
// ���������� ����� �������� ����� ��� ������.
node_AVL_Gus* insert_Gus(node_AVL_Gus* p, integer k)
{
	// ������� ����� k � ������ � ������ p
	if (p == 0) {
		node_AVL_Gus* r1 = nullptr;
		r1 = new node_AVL_Gus(k);
		if (r1 == nullptr) {
			// ������������ ������ �� ������ ������������.
			printf("Problem: not enough memory on your equipment for r1 in insert_Gus my_agregat_amg...\n");
			printf("Please any key to exit...\n");
			//getchar();
			system("pause");
			exit(1);
		}
		return r1;
	}
	if (k < p->key)
		p->left = insert_Gus(p->left, k);
	else
		p->right = insert_Gus(p->right, k);

	return balance_Gus(p);
} // insert

  // �������� ������ Si Transpose �� ��� ������ � ��������� root_Gus_set.
// ��������� ������ �� ������ ������ � ������.
void formirate_F_SiTranspose_AVL_Gus(node_AVLST*& p, node_AVL_Gus*& root_Gus_set, integer& imarker75_scan)
{
	if (p != nullptr) {
		formirate_F_SiTranspose_AVL_Gus(p->left, root_Gus_set, imarker75_scan);
		formirate_F_SiTranspose_AVL_Gus(p->right, root_Gus_set, imarker75_scan);
		root_Gus_set = insert_Gus(root_Gus_set, p->key.i);
		imarker75_scan++;
	}
}

// �������� ������ Si Transpose �� ��� ������ � ��������� root_Gus_set.
// ��������� ������ �� ������ ������ � ������.
void formirate_F_SiTranspose_AVL_Gus(Taccumulqtor_list*& p, node_AVL_Gus*& root_Gus_set, integer& imarker75_scan)
{
	Taccumulqtor_list* buf = p;
	if (buf != nullptr) {

		root_Gus_set = insert_Gus(root_Gus_set, buf->ikey);
		imarker75_scan++;

		buf = buf->next;
	}
	buf = nullptr;
}


// �������� ������ Si Transpose �� ��� ������ � ��������� root_Gus_set.
// ��������� ������ �� ������ ������ � ������.
void formirate_F_SiTranspose_AVL_Gus2(Taccumulqtor_list*& p, node_AVL_Gus*& root_Gus_set, integer& imarker75_scan,
	bool*& this_is_F_node, bool*& this_is_C_node)
{
	Taccumulqtor_list* buf = p;
	if (buf != nullptr) {
		if ((this_is_F_node[buf->ikey] == false) && (this_is_C_node[buf->ikey] == false)) {
			root_Gus_set = insert_Gus(root_Gus_set, buf->ikey);
			imarker75_scan++;
		}
		buf = buf->next;
	}
} // formirate_F_SiTranspose_AVL_Gus2

// �������� ������ Si Transpose �� ��� ������ � ��������� root_Gus_set.
// ��������� ������ �� ������ ������ � ������.
void formirate_F_SiTranspose_AVL_Gus2(node_AVLST*& p, node_AVL_Gus*& root_Gus_set, integer& imarker75_scan,
	bool*& this_is_F_node, bool*& this_is_C_node)
{
	if (p != nullptr) {
		formirate_F_SiTranspose_AVL_Gus2(p->left, root_Gus_set, imarker75_scan, this_is_F_node, this_is_C_node);
		formirate_F_SiTranspose_AVL_Gus2(p->right, root_Gus_set, imarker75_scan, this_is_F_node, this_is_C_node);
		if ((this_is_F_node[p->key.i] == false) && (this_is_C_node[p->key.i] == false)) {
			root_Gus_set = insert_Gus(root_Gus_set, p->key.i);
			imarker75_scan++;
		}
	}
}

// �������� root_Gus_set � ��������� set.
// ��������� ������ �� ������ ������ � ������.
void formirate_root_Gus_set__2__set(node_AVL_Gus*& root_Gus_set, integer*& set, integer& ic_986)
{
	if (root_Gus_set != nullptr) {
		formirate_root_Gus_set__2__set(root_Gus_set->left, set, ic_986);
		formirate_root_Gus_set__2__set(root_Gus_set->right, set, ic_986);
		set[ic_986] = root_Gus_set->key;
		ic_986++;
	}
}



// ���������� true ���� ���� ������ � ������
bool isfound_Gus(node_AVL_Gus* p, integer k)
{
	if (p == 0) return false; // �� ������.
	if (k < p->key)
		return isfound_Gus(p->left, k);
	else if (k > p->key)
		return isfound_Gus(p->right, k);
	else return true; // ������.
}

// ������ �������� ��������� ������.
void clear_AVL_Gus(node_AVL_Gus* p)
{
	if (p != 0) {
		clear_AVL_Gus(p->left);
		clear_AVL_Gus(p->right);
		// ������� ����.
		delete p;
		p = 0;
	}
} // clear_AVL_Gus

  // �������� ���� � ��������� �������� � ����������� ������������������.
node_AVL_Gus* findmin_Gus(node_AVL_Gus* p)
{
	return p->left ? findmin_Gus(p->left) : p;
} // findmin

node_AVL_Gus* findmax_Gus(node_AVL_Gus* p)
{
	// ����� ���� � ����������� ������ � ������ p
	if (p != 0) {
		return p->right ? findmax_Gus(p->right) : p;
	}
	else {
		// �� ����� ��������� ����� ������� ���������.
		return 0;
	}
} // findmax

integer get_max_AVL_Gus(node_AVL_Gus* p)
{
	// ����������� ������������� ���� � ������.
	return p->right ? get_max_AVL_Gus(p->right) : p->key;
}

node_AVL_Gus* removemin_Gus(node_AVL_Gus* p)
{
	// �������� ���� � ����������� ������ �� ������ p
	if (p->left == 0)
		return p->right;
	p->left = removemin_Gus(p->left);
	return balance_Gus(p);
}

// �������� ��������� �������� �� AVL ������
// � ������ ����������� ������������.
// �� ������������ �������� ����� �� �������� ��������.
node_AVL_Gus* remove_AVL_Gus(node_AVL_Gus* p, integer k)
{
	// ��������� ������� ���������� 
	// ��� ��������� �� ��� ����� �����.
	// �������� ����� k �� ������ p
	if (p == 0) return 0;
	// �������� ����� ������� ��������.
	if (k < p->key)
		p->left = remove_AVL_Gus(p->left, k);
	else if (k > p->key)
		p->right = remove_AVL_Gus(p->right, k);
	else // k==p->key
	{
		node_AVL_Gus* q = p->left;
		node_AVL_Gus* r = p->right;
		delete p;
		p = 0;
		if (r == 0) return q;
		node_AVL_Gus* min = findmin_Gus(r);
		min->right = removemin_Gus(r);
		min->left = q;
		return balance_Gus(min);
	}

	// ��� ������ �� �������� ������ ������������.
	return balance_Gus(p);
}

// ������� ����� � � ������ ���� ����� k_search
// ��� ��� � ������ ��� ����������� ����� �_search �� �.
// ���������� ����� �������� ����� ��� ������.
node_AVL_Gus* insert_and_modify_Gus(node_AVL_Gus* p, integer k, integer k_search)
{
	if (isfound_Gus(p, k_search) == false) {
		//   ���� � ������ ���.
		return insert_Gus(p, k);
	}
	else {
		// �������� k_search
		p = remove_AVL_Gus(p, k_search); // ����������� ��������
										 // ������� �.
		return insert_Gus(p, k);
	}
}

// print_AVL for debug.
void print_AVL_Gus(node_AVL_Gus* p)
{
	if (p != 0) {
		print_AVL_Gus(p->left);
		for (integer i = 0; i <= p->height; i++) {
			printf(" ");
		}
#if doubleintprecision == 1
		printf("%lld\n", p->key);
#else
		printf("%d\n", p->key);
#endif

		print_AVL_Gus(p->right);
	}
} // print_AVL

  // ������������ ��� ������
  // 12 ������� 2015 �����������������.
void test_AVL_Gus()
{
	node_AVL_Gus* root = 0;
	integer d3;
	d3 = rand();
	root = remove_AVL_Gus(root, d3);
	for (integer i = 0; i < 10; i++)
	{
		integer d;
		d = rand();
		root = insert_and_modify_Gus(root, d, d);
		print_AVL_Gus(root);
		if (i == 5) {

			//41 18467 6334


			integer d1;
			d1 = 41;
			integer d2;
			d2 = rand();
			root = insert_and_modify_Gus(root, d2, d1);
			print_AVL_Gus(root);
			printf("remove 41 \n");
			root = remove_AVL_Gus(root, d1);
			print_AVL_Gus(root);
			printf("found max\n");
			node_AVL_Gus* emax;
			emax = findmax_Gus(root);
#if doubleintprecision == 1
			printf("maximum id %lld\n", emax->key);
#else
			printf("maximum id %d\n", emax->key);
#endif

			emax = 0;
			//clear_AVL(root);
			//root = 0;
			print_AVL_Gus(root);
		}

		system("pause");
	}
	system("pause");
}

// ����� ������ � ������� ������������ � ��� ������ ��� ������������ ���������� ���������.

#endif