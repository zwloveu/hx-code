fn main() {
    use std::fmt;

    #[derive(Debug)]
    struct Structure(i32);

    impl fmt::Display for Structure {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            write!(f, "{}", self.0)
        }
    }

    println!("{}", Structure(7));
    println!("{:?}", Structure(7));

    #[derive(Debug)]
    struct Complex {
        real: f64,
        imag: f64,
    }

    impl fmt::Display for Complex {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            write!(f, "{} + {}i", self.real, self.imag)
        }
    }

    let complex: Complex = Complex {
        real: 3.3,
        imag: 7.2,
    };
    println!("{}", complex);
    println!("{:?}", complex);

    struct List(Vec<Complex>);
    impl fmt::Display for List {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            let vec: &Vec<Complex> = &self.0;

            write!(f, "[")?;

            for (index, v) in vec.iter().enumerate() {
                if index != 0 {
                    write!(f, ", ")?;
                }
                write!(f, "{{real: {:.2}, imag: {:.2}}}", v.real, v.imag)?;
            }

            write!(f, "]")
        }
    }
    let list = List(vec![
        Complex {
            real: 1.0,
            imag: 1.2,
        },
        Complex {
            real: 2.1,
            imag: 7.9,
        },
    ]);
    println!("{}", list);
}
