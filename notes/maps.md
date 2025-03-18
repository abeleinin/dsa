# Maps

## **Insertion**

`std::map` is an ordered container that stores key-value pairs sorted by key. There are multiple ways to insert elements:

### Using the Subscript Operator (`[]`)
```cpp
std::map<int, std::string> myMap;
myMap[10] = "Ten"; // Inserts {10, "Ten"} if key 10 doesn't exist, otherwise updates the value.
```
- Creates a default value if the key doesn’t exist.
- Can be used for both insertion and updating.

### Using `insert()`
```cpp
myMap.insert({5, "Five"}); // Inserts {5, "Five"} only if key 5 is not already present.
```
- Does not overwrite existing values.
- Returns a `std::pair` indicating whether the insertion was successful.

### Using `emplace()`
```cpp
myMap.emplace(15, "Fifteen"); // Constructs the value in place.
```
- More efficient for complex objects since it avoids unnecessary copying.
