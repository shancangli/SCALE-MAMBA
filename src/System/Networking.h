/*
Copyright (c) 2017, The University of Bristol, Senate House, Tyndall Avenue, Bristol, BS8 1TH, United Kingdom.
Copyright (c) 2018, COSIC-KU Leuven, Kasteelpark Arenberg 10, bus 2452, B-3001 Leuven-Heverlee, Belgium.

All rights reserved
*/
#ifndef _Networking
#define _Networking

#include "SystemData.h"

/* Create the server socket and intialize the socket address structure
 *   max is the max number of connections to expect
 */
int OpenListener(int port, int max= 1);

/* Connect for the client */
int OpenConnection(const string &hostname, int port);

/* This gets nthreads connections between SD.n players
 * Returns the *connection* socket information in csocket[thread][player]
 * The variable ssocket contains the server socket number.
 * The server portnum for each player is in the vector portnum
 */
void Get_Connections(int &ssocket, vector<vector<int>> &csocket,
                     vector<int> &portnum, unsigned int me,
                     const SystemData &SD, bool verbose= false);

void Close_Connections(int ssocket, vector<vector<int>> &csocket,
                       unsigned int me);

#endif
