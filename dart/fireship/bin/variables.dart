void main() {
  int num1 = 2;
  double num2 = 3.0;
  bool isTrue = true;

  print((num1 + num2) is int);
  print((num1 + num2).runtimeType);

  String str = 'hello';

  // String interpolation
  print('The type of $str is a String? ${str is String}');
}
