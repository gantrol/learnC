# For Long Run

## for every function call

- Call a function.
- Check if the return value is an error (and it must look that up each time, too).
- Then, cleanup all the resource created so far.
- Lastly, print out an error message that hopefully helps.

## Mac

```shell
sudo xcode-select --switch /Applications/Xcode-beta.app/Contents/Developer\


# clang -fsanitize=thread -g -o main-race main-race.c -lpthread\

```