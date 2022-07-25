template <typename T_element>
class Sorts;
template <typename T_element>
class Utility
{
	friend class Sorts<T_element>;
	void swap(T_element &element1, T_element &element2);
};
