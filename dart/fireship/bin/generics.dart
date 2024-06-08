void main() {
  Box<String> box1 = Box<String>("apple");
  print('Value inside box: ${box1.openBox()}');

  var box2 = Box<List<int>>([1, 2]);
  print('Value inside box: ${box2.openBox()}');
}

class Box<T> {
  final T value;
  Box(this.value);

  T openBox() {
    return value;
  }
}
