
### `std::map`

`std::map` is a sorted associative container that stores key-value pairs with unique keys. Keys are used to index the elements in the map.

To use `std::map`, include the `<map>` header:

```cpp
#include <map>
```

Declare a map with `std::map<KeyType, ValueType>`, for example:

```cpp
std::map<std::string, int> myMap;
```

Use the `insert()` function or `operator[]` to add key-value pairs to the map:

```cpp
myMap.insert(std::make_pair("apple", 10));
myMap["banana"] = 20;
```


To access the value associated with a key:

```cpp
int appleCount = myMap["apple"];
int bananaCount = myMap.at("banana");
```

Use `find()` to check if a key exists in the map:

```cpp
if(myMap.find("orange") != myMap.end()) {
    // Key exists
} else {
    // Key does not exist
}
```


We can use range-based for loop to iterate through the map:

```cpp
for(const auto& pair : myMap) {
    std::cout << pair.first << ": " << pair.second << std::endl;
}
```

that "auto" is actually `std::pair`, you just need to know that it has "first" and "second" element.


If you want to delete a key-value pair:

```cpp
myMap.erase("apple");
```

If you want to know the number of key-value pairs:

```cpp
size_t size = myMap.size();
```

### Exercise: (you don't have to do this if you think it's easy and can proceed straight to the timings file to do exercise 2 in there)

  - Declare a std::map named fruitInventory with std::string as the key type and int as the value type.
  - Insert 10 apples, 20 bananas, and 15 oranges into the fruitInventory.
  - Write a loop to iterate over the fruitInventory and print the name and quantity of each fruit.
  - A customer buys 3 apples and 5 bananas. Update the inventory accordingly.
  - A supplier adds 10 more oranges to the inventory. Update the inventory accordingly.
  - Check if there are any grapes in the fruitInventory and print a message indicating whether grapes are available.
  - The oranges are found to be rotten. Remove oranges from the fruitInventory.
  - print final inventory





