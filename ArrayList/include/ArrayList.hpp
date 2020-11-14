#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
using namespace std;

template <typename Object>
class ArrayList{
	private:
		Object *items;
		int length;
		int capacity;
	
		void reserve(int newcapacity){
			if(newcapacity <= capacity) return;
			Object *tmp = new Object[newcapacity];
			for(int i = 0; i < length; i++){
				tmp[i]=items[i];
			}
			delete [] items;
			items = tmp;
			capacity = newcapacity;
		}
	public:
		ArrayList(){
			length = 0;
			capacity = 100;
			items = new Object[capacity];
		}
		int size()const{
			return length;
		}
		bool isEmpty()const{
			return length ==0;
		}
		void insert(int index, const Object& item){
			if(length == capacity) reserve(2 * capacity);
			for(int i = length-1; i>=index; i--){
				items[i+1] = items[i];
			}
			items[index] = item;
			length++;
		}
		void add(const Object& item){
			insert(length, item);
		}
		const Object& first()const{
			return items[0];
		}
		const Object& last()const{
			return items[length-1];
		}
		void clear(){
			length = 0;
		}
		const Object& elementAt(int index)const{
			return items[index];
		}
		int indexOf(const Object& item)const{
			for(int index = 0; index < length; index++){
				if(items[index]== item) return index;
			}
		}
		void remove(const Object& item){
			int index = indexOf(item);
			removeAt(index);
		}
		void removeAt(int index){
			for(int i = index+1; i < length; i++){
				items[i-1] = items[i];
			}
			length--;
		}
		friend ostream& operator<<(ostream& screen,ArrayList<Object>& right){
			screen<<endl;
			for(int index = 0; index<right.length; index++){
				screen<<right.items[index]<<" ";
			}
			screen<<endl;
			return screen;
		}
		~ArrayList(){
			delete [] items;
		}
};


#endif