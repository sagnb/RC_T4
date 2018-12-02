# RC_T4

## Description
RC_T4 is a project made for the discipline of computer networks. In this project we are working on a graph with n nodes representing ASs, and all nodes must have paths for all other nodes.

The goal is given two nodes to discover:
1. the smallest path between hosts Hx and Hy
2. the best way (lower cost considering the costs of arrests)
3. the best path in terms of latency (lower total latency), that is, considering the number of jumps / routers within nodes (ASs)

## Dependencies
### TODO

## Compilation
In your terminal, write:
```bash
make
```
or
```
make help
```
for more instructions

## Usage
In your terminal, write after compiling:
```
./a.out -g <file_name_graph> -h <file_name_hosts>
```
where file_name_graph must be replaced by the file name of the graph
where file_name_hosts must be replaced by the file name of the hosts

## Input FILES

### Graph
The first line must contain the number of nodes followed by the following lines containing the numbers of the connected nodes and the capacity of the connection. Ex.:
```
5
1 2 10
2 3 11
3 4 3
4 5 20
```

### Hosts
File containing host1 / AS1 host2 / AS2 pairs. This means that host1 is connected to AS1 and host2 is connected to AS2. Ex.:
```
H1 AS2 H2 AS13

H3 AS5 H4 AS1

...

Hx AS4 Hy AS12
```

## Status

[X] running

[ ] stoped

[ ] finished

## Contributing
[Guilherme Neri](https://github.com/161150744)
[Lucas Antunes](https://github.com/lucasantunesdealmeida)