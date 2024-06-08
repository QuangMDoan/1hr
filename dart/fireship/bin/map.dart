void main() {
  var book = <String, dynamic>{
    'title': 'Moby Dick',
    'author': 'Herman Melville',
    'pages': 752,
  };

  print(book['title']);
  book['published'] = 1851;

  print(book.keys.toList());
  // iterable
  print(book.values);

  for (MapEntry b in book.entries) {
    print('Key ${b.key}, Value ${b.value}');
  }

  book.forEach((k, v) {
    print('Key ${k}, value ${v}');
  });

  book.forEach((k, v) => print("Key : $k, Value: $v"));
}
