cmake_minimum_required(VERSION 4.0)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSA
        "BInary Search/CellTowerBInSearch.cpp"
        "BInary Search/tle.cpp"
        CPLadder/AZDiv2a.cpp
        DP/atcoder/coins_prob.cpp
        DP/atcoder/DP_on_DAGs.cpp
        DP/atcoder/grid.cpp
        DP/atcoder/J.Sushi.cpp
        DP/atcoder/knapsack1.cpp
        DP/atcoder/LCS.cpp
        DP/atcoder/M.candies.cpp
        DP/CSES/bookshop.cpp
        DP/CSES/first5Iterative.cpp
        DP/base.cpp
        DP/CSESdp.cpp
        DP/problems.cpp
        DP/test.cpp
        "graphs/Algorithms Standard Templates/DisjointSetUnion.cpp"
        "graphs/Algorithms Standard Templates/ShortestPathAlgos.cpp"
        "graphs/Algorithms Standard Templates/ShortestPathTopo.cpp"
        "graphs/Algorithms Standard Templates/topologicalsort.cpp"
        graphs/CSES/buildingroadsQ3.cpp
        graphs/CSES/monstersQ7.cpp
        graphs/CSES/Q1_6.cpp
        graphs/CSES/RoundTripQ6.cpp
        graphs/CSES/shortestroutes1.cpp
        graphs/EDU/cuttinggraph.cpp
        graphs/ConstructAPallindromeAtcoder.cpp
        graphs/DestroyingArray.cpp
        graphs/destroyingroads.cpp
        graphs/DoubleDotsAtcoder.cpp
        graphs/DSUEDU.cpp
        graphs/FedorAndEssay.cpp
        graphs/maze.cpp
        graphs/NewYearPemutations.cpp
        graphs/quarrel.cpp
        graphs/universalDSU.cpp
        "greedy/AZ Constructive/Constructive.cpp"
        greedy/CF_1657E.cpp
        greedy/chatroom.cpp
        "greedy/D.Megalomania(atcoder).cpp"
        "greedy/DoubleLexicographically_Minimum(CF).cpp"
        greedy/greedy_AZ.cpp
        "greedy/RoomAllocation(CSES).cpp"
        greedy/RoundTrip.cpp
        greedy/Segments.cpp
        greedy/woodcutters.cpp
        "Number Theory/TLE/Common_Divisor_CSES.cpp"
        "Number Theory/TLE/D.divgame.cpp"
        "Number Theory/AZnumberTheorylvl1.cpp"
        "Number Theory/AZNumberTheorylvl2.cpp"
        "Number Theory/DoubleFactorial_atcoder.cpp"
        "Number Theory/Paulerdos_SPOJ.cpp"
        recursion/base.cpp
        "Sliding Windows/Multiset.cpp"
        "Sliding Windows/queueoptimization.cpp"
        "solved Codes/greedy/DoubleLexicographicallyMin.cpp"
        "solved Codes/greedy/Kcompleteword.cpp"
        "solved Codes/greedy/MinimumStickLength.cpp"
        "solved Codes/greedy/USBvsPS2.cpp"
        "solved Codes/String Hashing/stringmatchingCSES.cpp"
        "solved Codes/wewerejustchildren.cpp"
        "Two Pointers/cf-edu.cpp"
        "Two Pointers/CF_edu_totallength.cpp"
        "Two Pointers/TLEQuestions.cpp"
        Bin_Tries.cpp
        contestcode.cpp
        CPtemplate.cpp
        graph.cpp
        Kadanes_Algo_Template.cpp
        maxXORinArray.cpp
        stringHashing.cpp
        tempCodeRunnerFile.cpp
        trees.cpp
        tries_NoPointer.cpp
        tries_Pointer.cpp)
