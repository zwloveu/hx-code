fn main() {
    #[derive(Debug)]
    struct Structure(i32);

    #[derive(Debug)]
    struct Deep(Structure);

    println!("{:?} months in a year.", 12);
    println!(
        "{1:?} {0:?} is the {actor:?} name.",
        "Slater",
        "Christian",
        actor = "actor's",
    );

    let s3: Structure = Structure(3);
    println!("Now {:?} will print!, element is {:?}", s3, s3.0);

    let d7: Deep = Deep(Structure(7));
    println!("Now {:?} will print!, element is {:?}", d7, d7.0);
    println!("Now {:#?} will print!", d7);

    dbg!(s3);
    dbg!(d7);
}
