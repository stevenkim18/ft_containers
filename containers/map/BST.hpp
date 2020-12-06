#ifndef BST_HPP
# define BST_HPP

# include <iostream>

template <typename T>
struct Bnode
{
    Bnode   *parent;
    Bnode   *left;
    T        data;
    Bnode   *right;
};

template <typename T>
class BST
{
    private:
        Bnode<T>*	_root;
		size_t		_size;
        
    protected:
        // 삽입
        Bnode<T>*	insert_node(Bnode<T>* node, T &data)
		{	
			// root가 null일때
			if (node == nullptr)
			{
				node = new Bnode<T>;
				node->data = data;
				node->left = nullptr;
				node->right = nullptr;
				node->parent = nullptr;
				_size++;
			}
			else if (data < node->data)
			{
				node->left = insert_node(node->left, data);
				node->left->parent = node;
			}
			else if (data > node->data)
			{
				node->right = insert_node(node->right, data);
				node->right->parent = node;
			}
			return (node);
		}
		// 중위 표기법
		void		print_in_order(Bnode<T> *node)
		{
			if (node == nullptr)
				return ;
			print_in_order(node->left);
			std::cout << node->data << " "; 		// 일반 변수 타입 일때
		//	std::cout << "(" << node->data.first << ", " << node->data.second << ") "; 	// pair 일때!
			print_in_order(node->right);
		}
		// 탐색
		Bnode<T>*	search_node(Bnode<T>* node, T& data)
		{
			if (node == nullptr)
				return (nullptr);
			else if (data == node->data)
				return (node);
			else if (data < node->data)
				return search_node(node->left, data);
			else if (data > node->data)
				return search_node(node->right, data);
			return (nullptr);
		}
		// 최소값
		Bnode<T>*	find_min_node(Bnode<T>* node)
		{
			if (node == nullptr)
				return (nullptr);
			else if (node->left == nullptr)
				return (node);
			else
				return (find_min_node(node->left));
		}
		// 최대값
		Bnode<T>*	find_max_node(Bnode<T>* node)
		{
			if (node == nullptr)
				return (nullptr);
			else if (node->right == nullptr)
				return (node);
			else
				return find_max_node(node->right);
		}
		// 직후 원소 찾기
		Bnode<T>*	successor_node(Bnode<T>* node)
		{	
			// 오른쪽 자식이 있으면 그 서브트리의 최소값이 직후 값!
			if (node->right != nullptr)
				return find_min_node(node->right);
			else
			{
				Bnode<T>*	parent = node->parent;
				Bnode<T>*	current = node;

				while ((parent != nullptr) && (current == parent->right))
				{
					current = parent;
					parent = current->parent;
				}
				return (parent);
			}
		}
		// 직전 원소 찾기
		Bnode<T>*	predecessor_node(Bnode<T>* node)
		{
			if (node->left != nullptr)
				return (find_max_node(node->left));
			else
			{
				Bnode<T>*	parent = node->parent;
				Bnode<T>*	current = node;

				while ((parent != nullptr) && (current == parent->left))
				{
					current = parent;
					parent = current->parent;
				}
				return (parent);
			}
		}
		// 삭제
		Bnode<T>*	remove_node(Bnode<T>* node, T& data)
		{
			if (node == nullptr)
				return (nullptr);

			// 삭제 부분!
			if (node->data == data)
			{	
				Bnode<T>* tmp_node = node;		// for delete removed node
				// 자식이 없을 떄
				if (node->left == nullptr && node->right == nullptr)
				{
					node = nullptr;
					delete tmp_node;
					_size--;
				}
				// 오른쪽 자식만 있을 때
				else if (node->left == nullptr && node->right != nullptr)
				{
					node->right->parent = node->parent;
					node = node->right;
					delete tmp_node;
					_size--;
				}
				// 왼쪽 자식만 있을 때
				else if (node->left != nullptr && node->right == nullptr)
				{
					node->left->parent = node->parent;
					node = node->left;
					delete tmp_node;
					_size--;
				}
				// 자식이 둘다 있을 때
				else
				{
					// successor or predecessor
					Bnode<T>*	successor = successor_node(node);
					node->data = successor->data;
					node->right = remove_node(node->right, successor->data);
				}
			}
			// 삭제 값이 더 클때 -> 오른쪽
			else if (node->data < data)
				node->right = remove_node(node->right, data);
			// 삭제 값이 더 작을떄 -> 왼쪽
			else
				node->left = remove_node(node->left, data);
			return (node);
		}
		void		delete_node(Bnode<T>* node)
		{
			if (node)
			{
				delete_node(node->left);
				delete_node(node->right);
				delete node;
			}
		}
	public:
		// 생성자 -> _root null로 초기화
		BST() : _root(nullptr), _size(0) {}
		// 소멸자
		~BST()
		{
			delete_node(_root);
		}
		size_t		get_size()	{ return (_size); }
		void		insert(T data)
		{
			_root = insert_node(_root, data);
		}
		void		print_in_order()
		{
			std::cout << "[ ";
			print_in_order(_root);
			std::cout << "]" << std::endl;
		}
		bool		search(T data)
		{
			Bnode<T>* result = search_node(_root, data);
			if (result)
				return (true);
			else
				return (false);
		}
		Bnode<T>*	find_min()
		{
			return (find_min_node(_root));
		}
		Bnode<T>*	find_max()
		{
			return (find_max_node(_root));
		}
		T&			successor(T data)
		{
			Bnode<T>* node = search_node(_root, data);
			Bnode<T>* s_node = successor_node(node);
			// if (s_node)
			return (s_node->data);
			// else	// 트리 안에 찾고자 하는 값이 없으면 자신 리턴
			// 	return (&data);
		}
		T&			predecessor(T data)
		{
			Bnode<T>* node = search_node(_root, data);
			Bnode<T>* p_node = predecessor_node(node);
			return (p_node->data);
		}
		void		remove(T data)
		{
			_root = remove_node(_root, data);
		}
};

#endif