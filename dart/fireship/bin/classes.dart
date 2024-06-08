void main() {
  Basic thing = Basic(55);
  thing.id;
  thing.doStuff();

  Basic.helper();
}

class Basic {
  int id;

  Basic(this.id);

  doStuff() {
    print('Hello my ID is $id');
  }

  static helper() {}
}
