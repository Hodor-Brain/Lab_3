#pragma once
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <conio.h>

using namespace std;

struct Element;
struct Node;
struct NodeList;

int** Matrix_creator(int n);

void Write_in_file(const char* filename, int n);

void Print_normal_matrix(int** matrix, int n);

int** Read_from_file(const char* filename, int n);

NodeList* Linked_storage(int** Matr, int n);

NodeList** Sequential_linked_storage(int** Matr, int n);

void Print_sequential_storage(NodeList** nodelist, int n);

NodeList* Summ_2_matrix(NodeList* first, NodeList* second, int n);

NodeList** Summ_2_matrix_sequential(NodeList** first, NodeList** second, int n);

NodeList** Sequential_linked_storage_reverse(int** Matr, int n);

NodeList** Matr_multiplication(NodeList** first, NodeList** second, int n);

void Print_matrix_linked(NodeList* matrix, int n);

void Print_matrix_sequential(NodeList** matrix, int n);

void Print_matrix_sequential_reverse(NodeList** matrix, int n);


struct Element 
{
	int data = 0, row = 0, column = 0;
};

struct Node 
{
	Element inf;
	Node* next;
	Node* prev;
};

struct NodeList 
{
	Node* head = NULL;
	Node* tail = NULL;

	void addLast(Element i) 
	{
		Node* node = new Node;

		node->inf = i;
		node->next = NULL;

		if (head == NULL) 
		{
			tail = node; 
			head = node;
		}
		else 
		{
			node->prev = tail;
			tail->next = node;
			tail = node;
		}
	}

	Node* find(int key)
	{
		Node* cur = head;
		while (cur)
		{
			if (cur->inf.data == key)break;
			cur = cur->next;
		}
		return cur;
	}

	bool remove(int key)
	{
		if (Node * pkey = find(key)) 
		{
			if (pkey == head) 
			{
				head = (head)->next;
				(head)->prev = 0;
			}
			else if (pkey == tail) 
			{
				tail = (tail)->prev;
				(tail)->next = 0;
			}
			else 
			{
				(pkey->prev)->next = pkey->next;
				(pkey->next)->prev = pkey->prev;
			}
			delete pkey;
			return true;
		}
		return false;
	}

	bool RemoveLast()
	{
		if (head == NULL) 
		{
			cout << "There are no elements!" << endl << endl;
			return false;
		}
		else 
		{
			Node* cur = tail;
			tail = (tail)->prev;
			(tail)->next = NULL;
			delete cur;
			cout << "Successful!" << endl;
			return true;
		}

	}

	void Print()
	{
		Node* cur = head;
		while (cur) 
		{
			cout << cur->inf.data << ' ';
			cur = cur->next;
		}
	}
};
