fn main() {
    // fmt::Debug: Uses the {:?} marker. Format text for debugging purposes.
    // fmt::Display: Uses the {} marker. Format text in a more elegant, user friendly fashion.

    println!("{} days", 31);

    println!("{0}, this is {1}. {1}, this is {0}", "Alice", "Bob");

    println!(
        "{subject} {verb} {object}",
        object = "the lazy dog",
        subject = "the quick brown fox",
        verb = "jumps over"
    );

    println!("Base 10:          {}", 69420);
    println!("Base 2 (binary):  {:b}", 69420);
    println!("Base 8 (octal):   {:o}", 69420);
    println!("Base 16 (hexadecimal): {:x}", 69420);

    println!("{number:>5}", number = 1);
    println!("{number:0>5}", number = 1);
    println!("{number:0<5}", number = 1);
    println!("{number:0>width$}", number = 1, width = 5);

    #[allow(dead_code)]
    #[derive(Debug)]
    struct Structure(i32);
    println!("{:?}", Structure(3));

    let number: f64 = 1.0;
    let width: usize = 5;
    println!("{number:0<width$}");
}
