void main() {
  List<int> list = [0, 1, 2, 3, 4, 5];

  print(list.sublist(2, 5));

  var list2 = List.filled(50, 'hello');

  for (String x in list2) {
    print(x);
  }

  list.forEach((n) => print(n));

  var doubled = list.map((n) => n * 2);
  print(doubled);

  var combined = [...list, ...doubled];
  print(combined);

  bool depressed = true;
  var cart = ['milk', 'eggs', if (depressed) 'Vodka'];
  print(cart);
}
