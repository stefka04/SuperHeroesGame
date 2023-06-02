#pragma once
static const short INITIAL_CAPACITY = 8;
template<typename T>
class MyVector
{
	T* data = nullptr;
	size_t size;
	size_t capacity;
private:
	void copyFrom(const MyVector<T>& other);
	void moveFrom(MyVector<T>&& other) noexcept;
	void resize();
	void assertIndex(size_t index) const;
	void free();
public:
	MyVector();
	MyVector(const MyVector<T>& other);
	MyVector(MyVector<T>&& other) noexcept;
	MyVector <T>& operator=(const MyVector<T>& other);
	MyVector <T>& operator=(MyVector<T>&& other) noexcept;
	~MyVector();

	size_t getSize() const;
	size_t getCapacity() const;
	
	const T& operator[](size_t index) const;
	T& operator[](size_t index);

	void pushBack(const T& item);
	void pushBack(const T&& item);
	void popAt(size_t index);

};

template <typename T> 
MyVector<T>::MyVector()
{
	capacity = INITIAL_CAPACITY;
	size = 0;
	data = new T[capacity];
}
template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
	copyFrom(other);
}
template <typename T>
void MyVector<T>::copyFrom(const MyVector<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}
template <typename T>
void MyVector<T>::free()
{
	delete[] data;
	data = nullptr;
	size = capacity = 0;
}
template <typename T>
MyVector<T>::~MyVector()
{
	free();
}
template <typename T>
MyVector <T>& MyVector <T>:: operator=(const MyVector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
template <typename T>
void MyVector<T>::moveFrom(MyVector<T>&& other) noexcept
{
	size = other.size;
	capacity = other.capacity;
	data = other.data;
	other.data = nullptr;
	other.size = other.capacity = 0;
}
template <typename T>
MyVector <T>& MyVector <T>:: operator=(MyVector<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
template <typename T>
MyVector <T>:: MyVector (MyVector<T>&& other) noexcept
{
	moveFrom(std::move(other));
}
template <typename T>
void MyVector <T>:: resize()
{
	capacity *= 2;
	T* resizedData = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		resizedData[i] = std::move(data[i]);
	}
	delete[] data;
	data = resizedData;
}
template <typename T>
size_t MyVector <T>::getSize() const
{
	return size;
}
template <typename T>
size_t MyVector <T>::getCapacity() const
{
	return capacity;
}
template <typename T>
void MyVector <T>::assertIndex(size_t index) const
{
	if (index >= size)
	{
		throw std::out_of_range("Index out of range!");
	}
}
template <typename T>
const T& MyVector <T>:: operator[](size_t index) const
{
	assertIndex(index);
	return data[index];
}
template <typename T>
T& MyVector <T>:: operator[](size_t index)
{
	assertIndex(index);
	return data[index];
}
template <typename T>
void MyVector <T>:: pushBack(const T& item)
{
	if (size == capacity)
	{
		resize();
	}
	data[size++] = item;
}
template <typename T>
void MyVector <T>::pushBack(const T&& item)
{
	if (size == capacity)
	{
		resize();
	}
	data[size++] = std::move(item);
}
template <typename T>
void MyVector <T>::popAt(size_t index)
{
	assertIndex(index);
	size--;
	for (size_t i = index; i < size; i++)
	{
		data[i] = std::move(data[i + 1]);
	}
}