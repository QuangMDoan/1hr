void main() {
  String color = 'blue';
  if (color == 'blue') {
  } else if (color == 'green') {
  } else {}

  if (color == 'red') print('hello red');

  String thing1 = '';
  if (thing1.isEmpty) ;

  String? thing2;
  if (thing2 != null) ;

  for (var i = 0; i < 5; i++) {
    print(i);
    // break;
    // continue;
  }

  int i = 0;
  while (i < 5) {
    print(i);
    i++;
  }

  i = 0;
  do {
    print(i);
  } while (i < 5);

  var txt = 'good';
  assert(txt != 'bad');
}
