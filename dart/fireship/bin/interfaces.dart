void main() {
  var e = Elephant('Bob');

  e.sayHi();
  e._saySecret();
}

class Elephant {
  final String name;

  final int _id = 23;

  Elephant(this.name);
  sayHi() => 'My Name is {$name}';
  _saySecret() => 'My id is {$_id}';
}
