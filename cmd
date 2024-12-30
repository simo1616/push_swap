#cat tous les ficjier *.c
find . -type f -name "*.c" -exec cat {} +

#norm:
c_formatter_42 -c sort_chunks.c


ARG="1 4 3 88 22 -332 65 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 67 3 87 23 12"; ./push_swap $ARG | ./checker_linux $ARG
ARG=$(seq -989 985 | shuf -n 500); ./push_swap $ARG | wc -l
ARG=$(seq -989 985 | shuf -n 100); ./push_swap $ARG | wc -l
./push_swap 2 5 6 9 -1
./push_swap -901 -552 -4 31 -333 394 980 -139 615 -842 -377 -174 3 -50 47 -815 283 330 304 -477 -408 983 -791 860 868 -88 -185 393 -231 -196 820 -134 60 -42 -193 -47 -265 -830 534 680 68 -912 -545 254 -709 652 -115 864 688 412 -527 -440 793 -834 1 -384 -416 916 714 535 -520 -849 -825 435 -840 -821 162 -908 -903 -826 -45 646 933 392 167 -690 610 -294 651 -192 6 -885 635 981 81 898 54 -417 465 398 -871 519 893 -168 -186 -562 -924 -347 801 139 | wc -l



git checkout debug-version 