# The 100 Game

A classic two-player counting game implemented in C. Play against the
computer, which uses the optimal multiple-of-11 strategy.

## Rules
- Players take turns adding a number from 1 to 10 to a running total.
- The player who makes the total reach exactly 100 wins.

## Build

```bash
cd 100-game
make
```

## Run

```bash
./game100
# or
make run
```

## Files
- `game100.c` - game source code
- `Makefile` - build rules

## Strategy tip
If you want to always win as the first player, leave the total on a
multiple of 11 after every one of your turns (11, 22, 33, ... 99).
