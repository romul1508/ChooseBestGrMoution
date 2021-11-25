# ChooseBestGrMoution Copyright 2021 Roman Ermakov
Choosing the best city bus schedule

ChooseBestGrMoution.exe solves the following problem
 
The city transport company wants to introduce such a scheme for the movement of city buses, 
which will reduce gas pollution in the city by reducing the number of buses used (and at the same time the cost of salaries for drivers, repairs, etc.). 
It turned out that to meet the needs of citizens on this route from 0:00 to 4:00 at least 4 buses must run, from 4:00 to 8:00 at least 8, 
from 8:00 to 12:00 at least 10, from 12:00 to 16:00 at least 7, from 16:00 to 20:00 at least 12, from 20:00 to 24:00 at least 4. 
In this case, each bus must be on the line continuously for 8 hours (one change). Help the company set up a timetable.
//----------------------------------------------------------

Solution (See project folder /doc)
In accordance with the conditions of the problem, namely, 
the fact that at least 12 buses must be involved from 16:00 to 20 : 00, 
we can conclude that this is the minimum number of buses(A, B, C, D, E, F, G, H, I, K, L, M).

As a result of solving this problem, 
it turned out that at the output several equivalent traffic schedules are obtained. 
The main assessment criterion is the total number of hours spent by all buses, 
while the best schedule of movement along the route is the one 
that requires the minimum time spent in shifts.

Here are two equivalent optimal time schedules : 208 hours.
1. Bus A operates in three shifts, 24 hours a day.
   Bus B also operates 24 hours in three shifts.
   The C bus operates in two shifts, the first working from 12 : 00 to 20 : 00 and the second from 20 : 00 to 4 : 00.
   Bus D, like bus C, is used in two shifts, and operates from 12 : 00 to 20 : 00 (first shift) and from 20 : 00 to 4 : 00 (second shift).
   The remaining eight buses are used in two shifts from 4 : 00 to 20 : 00.

2. Bus A operates from 12 : 00 to 20 : 00.
   Bus B operates from 12 : 00 to 20 : 00.
   Buses C, D, E, F, G, H operate in two shifts from 4 : 00 to 20 : 00.
   Each of the buses I, K, L, M is operated in three shifts, 24 hours a day.

The problem is being solved slowly but surely. However, the enumeration of options can be accelerated by using the appropriate development tools.
