# MINITALK

minitalk is a C programming project that demonstrates inter-process communication using signals. The two programs communicate exclusively through the SIGUSR1 and SIGUSR2 signals, allowing users to send an unlimited number of characters, including emojis, efficiently and quickly.

This project supports UTF-8 encoding, ensuring a rich and diverse character set for messages. While it serves primarily as a programming practice exercise, its robust design ensures reliable two-way communication, minimizing data loss during transmission to zero.

By leveraging signal-based communication, minitalk showcases a practical implementation of process interaction in Unix-like environments, making it a useful reference for those interested in systems programming.

## Getting Started

These instructions will help you get a copy of the project up and running.

### Installing

1. Clone the repository:
```
git clone https://github.com/xwojtuss/minitalk.git
```

2. Navigate to the project directory:
```
cd minitalk
```

3. Run the make command to build the project:
```
make
```

## Running the project

You need to open at least two terminals, in the first one run:
```
./server
```
The program will print the process ID of the server, we will use it when we run the client in the second (or third, or fourth and so on...) terminal:
```
./client [server pid] [the message that you want to send to the server]
```


## Running the tests

These tests check various functionalities, including emoji support and the ability to handle large messages.

- For a looped test, run:

```
bash ./test_loop.sh [server pid]
```
- For testing with a large number of characters, run:

```
bash ./test_million.sh [server pid]
```
- For general tests, use:

```
bash ./tests.sh [server pid]
```

## Authors

* **Wojtek Kornatowski** - [xwojtuss](https://github.com/xwojtuss)

## Acknowledgments

The tests included in this project were not written by me, and I cannot find the original authors.
