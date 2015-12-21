extern crate term;

use std::process::Command;
use std::path::Path;
use std::env;
use std::io::{self, Write};
use std::fs::File;

//Nothing atm
fn mash_init(){
    //let mut mash_config = try!(File::open(""));
}

fn mash_tokenize(input: &str) -> Vec<&str>{
    let ret: Vec<&str> = input.split_whitespace()
        .collect();
    ret
}

//Exec will actually start a process
fn mash_exec(command: &str, args: &[&str]) -> bool{
    match Command::new(command)
        .args(&args)
        .status() {
            Ok(result) => true,
            Err(result) => {
                println!("mash: {} is not a command", command);
                true
            }
        }
}

/*
 * This will check for things like cd and ls.
 * If it is none of those, it will run the process with mash_exec()
 */
fn mash_parse(mut args: Vec<&str>) -> bool{
    //The actual command is the first element in the vector
    let status = match args[0] {
        "ls" => {
            args.push("--color");
            mash_exec("ls", &args[1..])
        },
        "cd" => {
            match env::set_current_dir(&Path::new(args[1])).is_ok(){
                true => {
                    true
                },
                false => {
                    println!("That is not a directory");
                    true
                }
            }
        },
        "exit" => {
            println!("Exiting");
            false
        },
        command => mash_exec(command, &args[1..])
    };

    match status {
        status if status == false => {
            false
        },
        status => status
    }
}

fn mash_loop(){
    let mut input = String::new();
    let mut status: bool = true;
    while status {
        input.clear();
        let mut t = term::stdout().unwrap();
        t.fg(term::color::RED).unwrap();
        write!(t, "> ").unwrap();
        t.reset().unwrap();
        io::stdout().flush().unwrap();
        io::stdin().read_line(&mut input)
            .ok()
            .expect("Could not read line");

        let input: Vec<&str> = mash_tokenize(&input);
        status = mash_parse(input);
    }
}

fn main() {
    println!("Welcome to MASH, use 'help' to get help");
    mash_init();
    mash_loop();
}
