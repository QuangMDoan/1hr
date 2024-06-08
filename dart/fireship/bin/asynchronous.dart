// asynchronous computations usually provide their result as a Future or, if the result has multiple mparts, as a Stream.
// Asynchronous computations introduce asynchrony into a program. To accomodate that initial asynchrony, other plain Dart functions also need to become asynchronous
//
// To interact with asynchronous results, you can use the async and await keywords.
//
// Example: incorrectly using an asynchronous function

Future<String> createOrderMessage() async {
  var order = await fetchUserOrder();
  return order;
}

Future<String> fetchUserOrder() {
  return Future.delayed(const Duration(seconds: 4), () {
    return 'Grande Latte';
  });
}

Future<void> main() async {
  print(await createOrderMessage());
}
