Tentando empacotar!
W 587 H 233 L 220
Item[0]:208, 76, 30
Item[1]:208, 76, 30
Item[2]:208, 76, 30
Item[3]:208, 76, 30
Item[4]:208, 76, 30
Item[5]:208, 76, 30
Item[6]:208, 76, 30
Item[7]:208, 76, 30
Item[8]:208, 76, 30
Item[9]:208, 76, 30
Item[10]:208, 76, 30
Item[11]:208, 76, 30
Item[12]:110, 43, 25
Item[13]:110, 43, 25
Item[14]:110, 43, 25
Item[15]:110, 43, 25
Item[16]:110, 43, 25
Item[17]:110, 43, 25
Item[18]:110, 43, 25
Item[19]:110, 43, 25
Item[20]:110, 43, 25
Item[21]:92, 81, 55
Item[22]:92, 81, 55
Item[23]:92, 81, 55
Item[24]:92, 81, 55
Item[25]:92, 81, 55
Item[26]:92, 81, 55
Item[27]:92, 81, 55
Item[28]:92, 81, 55
Item[29]:81, 33, 28
Item[30]:81, 33, 28
Item[31]:81, 33, 28
Item[32]:120, 99, 115
Item[33]:120, 99, 115
Item[34]:120, 99, 115
Item[35]:111, 70, 48
Item[36]:111, 70, 48
Item[37]:111, 70, 48
Item[38]:111, 70, 48
Item[39]:111, 70, 48
Item[40]:111, 70, 48
Item[41]:111, 70, 48
Item[42]:111, 70, 48
Item[43]:111, 70, 48
Item[44]:111, 70, 48
Item[45]:98, 72, 46
Item[46]:98, 72, 46
Item[47]:95, 66, 31
Item[48]:95, 66, 31
Item[49]:95, 66, 31
iniciando os testes...
Item profundo: 32 
Item profundo: 33 
Item profundo: 34 
 ! --------------------------------------------------- CP Optimizer 22.1.1.0 --
 ! Satisfiability problem - 6 variables, 3 constraints
 ! TimeLimit            = 600
 ! Workers              = 1
 ! Initial process time : 0.01s (0.01s extraction + 0.00s propagation)
 !  . Log search space  : 47.8 (before), 47.8 (after)
 !  . Memory usage      : 267.1 kB (before), 267.1 kB (after)
 ! Using sequential search.
 ! ----------------------------------------------------------------------------
 !               Branches  Non-fixed            Branch decision
 *                     15  0.01s                437  = _int4
 ! ----------------------------------------------------------------------------
 ! Search completed, 1 solution found.
 ! ----------------------------------------------------------------------------
 ! Number of branches     : 15
 ! Number of fails        : 4
 ! Total memory usage     : 701.8 kB (658.2 kB CP Optimizer + 43.7 kB Concert)
 ! Time spent in solve    : 0.01s (0.01s engine + 0.01s extraction)
 ! Search speed (br. / s) : 1500.0
 ! ----------------------------------------------------------------------------
=======SOLUCAO 2D=======
Item[0]:40 43
Item[1]:298 122
Item[2]:437 26
========================
 ! --------------------------------------------------- CP Optimizer 22.1.1.0 --
 ! Satisfiability problem - 150 variables, 1225 constraints
 ! TimeLimit            = 1800
 ! Workers              = 1
 ! Initial process time : 0.04s (0.04s extraction + 0.00s propagation)
 !  . Log search space  : 1183.7 (before), 1183.7 (after)
 !  . Memory usage      : 1.6 MB (before), 1.6 MB (after)
 ! Using sequential search.
 ! ----------------------------------------------------------------------------
 !               Branches  Non-fixed            Branch decision
                     1000         49             87 != _int89
                     2000         53            177 != _int35
                     3000         44        F    28  = _int67
                     4000         42        F   148  = _int64
                     5000         41        F   158  = _int119
                     6000         58              0 != _int117
                     7000         46             95 != _int35
                     8000         45              3 != _int116
                     9000         45        F   116  = _int139
                    10000         46            164 != _int111
                    11000         46        F     7  = _int118
                    12000         43            135 != _int64
                    13000         44            394 != _int48
                    14000         55        F   223  = _int1
                    15000         72            344 != _int48
                    16000         46        F    85  = _int68
                    17000         46            150 != _int52
                    18000         46              2 != _int114
                    19000         46        F    80  = _int68
                    20000         43            329 != _int111
 ! Time = 0.17s, Average fail depth = 45, Memory usage = 8.5 MB
 !               Branches  Non-fixed            Branch decision
                    21000         50        F    71  = _int0
                    22000         43        F    12  = _int24
                    23000         50              2 != _int0
                    24000         50             91 != _int126
                    25000         78                 -
                    26000         43            114 != _int0
                    27000         50            139  = _int119
                    28000         64        F    42  = _int136
                    29000         50            115 != _int41
                    30000         54        F    66  = _int16
                    31000         54        F   253  = _int111
                    32000         50        F   115  = _int85
                    33000         83             75 != _int76
                    34000         61              0  = _int111
                    35000         50              0  = _int31
                    36000         73        F    71  = _int2
                    37000         74        F    87  = _int131
                    38000         66              1 != _int75
                    39000         83             55 != _int114
                    40000         50            353  = _int129
 ! Time = 0.30s, Average fail depth = 58, Memory usage = 8.9 MB
 !               Branches  Non-fixed            Branch decision
                    41000         49        F   122  = _int4
                    42000         39             92 != _int139
                    43000         34            234 != _int111
                    44000         99            200  = _int94
                    45000         46        F    32  = _int62
                    46000         48            195  = _int50
                    47000         48        F    54  = _int102
                    48000         56        F   121  = _int96
                    49000         56             66 != _int76
                    50000         64        F    26  = _int112
                    51000         66        F   132  = _int119
                    52000         65        F   362  = _int1
                    53000         69            189 != _int32
                    54000         66            217 != _int24
                    55000         36            306 != _int123
                    56000         36            167 != _int110
                    57000         56            355  = _int0
                    58000         91            185 != _int26
                    59000         61            239 != _int75
                    60000         53            140 != _int121
 ! Time = 0.45s, Average fail depth = 59, Memory usage = 9.2 MB
 !               Branches  Non-fixed            Branch decision
                    61000         54             29 != _int104
                    62000         82            145 != _int67
                    63000         83        F   110  = _int128
                    64000         94        F   117  = _int7
                    65000         74        F   100  = _int136
                    66000         42             49 != _int115
                    67000         41        F    57  = _int112
                    68000         41        F    58  = _int32
                    69000         53            100 != _int118
                    70000         53            167  = _int148
                    71000         50              0  = _int126
                    72000         43             30 != _int101
                    73000         57            136 != _int11
                    74000         69        F   148  = _int10
                    75000         51             71 != _int133
                    76000         53        F   136  = _int83
                    77000         46              3 != _int17
                    78000         47             84 != _int16
                    79000         59        F   104  = _int28
                    80000         51            240 != _int39
 ! Time = 0.58s, Average fail depth = 60, Memory usage = 9.3 MB
 !               Branches  Non-fixed            Branch decision
                    81000         50             78 != _int19
                    82000         52        F   166  = _int35
                    83000         69        F   306  = _int114
                    84000         76        F   175  = _int102
                    85000         61        F    98  = _int96
                    86000         82            290 != _int114
                    87000         78        F    15  = _int126
                    88000         57              0  = _int43
                    89000         55            197 != _int6
                    90000         50             18 != _int103
                    91000         83        F   115  = _int6
                    92000         45        F     8  = _int96
                    93000         67        F   203  = _int6
                    94000         87             59 != _int111
                    95000         75        F        -
                    96000         66        F   116  = _int122
                    97000         79            155 != _int3
                    98000         76            219 != _int1
                    99000         76        F   164  = _int114
                     100k         86             50  = _int83
 ! Time = 0.77s, Average fail depth = 59, Memory usage = 9.5 MB
 !               Branches  Non-fixed            Branch decision
                     101k         92            154 != _int23
                     102k         75            162 != _int18
                     103k         76        F     4  = _int134
                     104k         70            302 != _int120
                     105k         70        F     3  = _int64
                     106k         90             62  = _int7
                     107k         95        F    45  = _int82
                     108k         63            105 != _int123
                     109k         63            285 != _int24
                     110k         68        F   222  = _int24
                     111k         47        F   141  = _int53
                     112k         39        F   219  = _int30
                     113k         40        F   167  = _int17
                     114k         74        F   125  = _int17
                     115k         76             84 != _int16
                     116k         79        F    43  = _int6
                     117k         80        F    63  = _int10
                     118k         80             29 != _int10
                     119k         77        F    40  = _int4
                     120k         87             93 != _int110
 ! Time = 0.96s, Average fail depth = 63, Memory usage = 10.2 MB
 !               Branches  Non-fixed            Branch decision
                     121k         78            120 != _int109
                     122k         38             91 != _int119
                     123k         44        F     3  = _int100
                     124k         55             35 != _int130
                     125k         55            242 != _int123
                     126k         51             96 != _int98
                     127k         67        F    81  = _int34
                     128k         45             19 != _int132
                     129k         50        F   341  = _int99
                     130k         52            104 != _int104
                     131k         60        F    84  = _int99
                     132k         73             22 != _int67
                     133k         63             25 != _int74
                     134k         63        F    42  = _int74
                     135k         66            127 != _int131
                     136k         74        F     0 != _int26
                     137k         91            363  = _int24
                     138k         84        F   165  = _int20
                     139k         86        F   310  = _int123
                     140k         96             53 != _int123
 ! Time = 1.09s, Average fail depth = 62, Memory usage = 9.7 MB
 !               Branches  Non-fixed            Branch decision
                     141k         93            419 != _int102
                     142k         93        F    42  = _int5
                     143k         90        F   175  = _int6
                     144k         90            207 != _int6
                     145k         84        F   118  = _int1
                     146k         84             70 != _int68
                     147k         91        F   162  = _int68
                     148k         81            136 != _int133
                     149k         78        F    95  = _int135
                     150k         78             94 != _int125
                     151k         84        F   116  = _int10
                     152k         70              2 != _int135
                     153k         67        F   161  = _int24
                     154k         67            463  = _int102
                     155k         52             14 != _int11
                     156k         73            109 != _int116
                     157k         75        F   149  = _int117
                     158k         75        F    45  = _int30
                     159k         84             92 != _int19
                     160k         85            114 != _int19
 ! Time = 1.24s, Average fail depth = 61, Memory usage = 9.8 MB
 !               Branches  Non-fixed            Branch decision
                     161k         89             50 != _int18
                     162k        100            174 != _int18
                     163k         88        F   262  = _int120
                     164k         89             35  = _int85
                     165k         76        F    26  = _int74
                     166k         69        F    80  = _int34
                     167k         70        F    99  = _int64
                     168k         72        F   447  = _int66
                     169k        111            416 != _int66
                     170k         72             40 != _int134
                     171k         64              0 != _int28
                     172k         66        F   126  = _int28
                     173k         69        F   425  = _int114
                     174k         75        F   148  = _int131
                     175k         60            151 != _int142
                     176k         47             79 != _int113
                     177k         46            169 != _int111
                     178k         47        F   311  = _int111
                     179k         43        F   146  = _int32
                     180k         50        F   222  = _int99
 ! Time = 1.36s, Average fail depth = 62, Memory usage = 10.0 MB
 !               Branches  Non-fixed            Branch decision
                     181k         37        F    49  = _int32
                     182k         71              0  = _int16
                     183k         50            150 != _int34
                     184k         44        F    19  = _int110
                     185k         49        F   115  = _int65
                     186k         48             72 != _int114
                     187k         83        F     5  = _int114
                     188k         83        F   204  = _int24
                     189k         85             10 != _int24
                     190k         77             19 != _int109
                     191k         54        F    75  = _int18
                     192k         79            149 != _int145
                     193k         41             45  = _int20
                     194k         44        F   129  = _int34
                     195k         44        F     1  = _int16
                     196k         45            159 != _int120
                     197k         66              0 != _int101
                     198k         56             18 != _int96
                     199k        114        F    78  = _int96
                     200k         96             58 != _int10
 ! Time = 1.51s, Average fail depth = 60, Memory usage = 10.0 MB
 !               Branches  Non-fixed            Branch decision
                     201k         97        F    71  = _int10
                     202k         85        F   324  = _int30
                     203k         85            246 != _int30
                     204k         75        F     8  = _int16
                     205k         46            159 != _int18
                     206k         61             94 != _int19
                     207k         44             55 != _int23
                     208k         57             50 != _int100
                     209k         53             92 != _int116
                     210k         44             24 != _int34
                     211k         45        F    32  = _int111
                     212k         71             43 != _int111
                     213k         72        F   236  = _int111
                     214k         73        F    47  = _int113
                     215k         86            145 != _int113
                     216k         62        F    74  = _int117
                     217k         62            199 != _int117
                     218k         63        F   378  = _int102
                     219k         83            225 != _int18
                     220k         62             73 != _int121
 ! Time = 1.66s, Average fail depth = 60, Memory usage = 10.8 MB
 !               Branches  Non-fixed            Branch decision
                     221k         70        F    59  = _int100
                     222k         58        F   261  = _int81
                     223k         58        F    46  = _int121
                     224k         63            126 != _int110
                     225k         53        F   266  = _int0
                     226k         53             93 != _int24
                     227k         61        F    19  = _int81
                     228k         49        F   101  = _int103
                     229k         49             58 != _int32
                     230k         45              0  = _int103
                     231k         62            192 != _int120
                     232k         51             20 != _int131
                     233k         55            197 != _int120
                     234k         52            117 != _int103
                     235k         46              1 != _int96
                     236k         51        F    98  = _int66
                     237k         77             82 != _int70
                     238k         78        F   140  = _int16
                     239k         86        F   109  = _int22
                     240k         90            112 != _int22
 ! Time = 1.80s, Average fail depth = 59, Memory usage = 10.1 MB
 !               Branches  Non-fixed            Branch decision
                     241k         52            156 != _int7
                     242k         53            118 != _int7
                     243k         57        F   114  = _int8
                     244k         64        F   108  = _int8
                     245k         66            131 != _int8
                     246k         69             36 != _int77
                     247k         73            283 != _int117
                     248k         73        F    18  = _int117
                     249k         74        F   114  = _int11
                     250k         85        F   103  = _int11
                     251k         58        F   461  = _int135
                     252k         59            336 != _int135
                     253k         60        F   451  = _int135
                     254k         47        F   131  = _int36
                     255k         36             75 != _int123
                     256k         36        F   279  = _int123
                     257k         37             59 != _int123
                     258k         38            334 != _int24
                     259k         78             55  = _int7
                     260k         64             27  = _int120
 ! Time = 1.95s, Average fail depth = 61, Memory usage = 11.4 MB
 !               Branches  Non-fixed            Branch decision
                     261k         37             85  = _int22
                     262k         42        F   134  = _int134
                     263k         63             61 != _int131
                     264k         72            109  = _int17
                     265k         27            124 != _int133
                     266k         53        F   404  = _int117
                     267k         58             92 != _int125
                     268k         50        F   142  = _int0
                     269k         62        F    49  = _int83
                     270k         43        F   179  = _int27
                     271k         45            115  = _int146
                     272k         25            152 != _int27
                     273k         63            225 != _int27
                     274k         63             47 != _int98
                     275k         84        F    85  = _int98
                     276k         89        F    57  = _int98
                     277k         83        F   151  = _int3
                     278k         64            183 != _int132
                     279k         64            219 != _int132
                     280k         68        F   221  = _int132
 ! Time = 2.13s, Average fail depth = 62, Memory usage = 10.3 MB
 !               Branches  Non-fixed            Branch decision
                     281k         28            234  = _int21
                     282k         32            117 != _int13
                     283k         40             13  = _int83
                     284k         41             57 != _int115
                     285k         40             22 != _int76
                     286k         37             68  = _int104
                     287k         62        F    49  = _int14
                     288k         59             31 != _int99
                     289k         53            176 != _int8
                     290k         68        F    45  = _int25
                     291k         70        F    11  = _int68
                     292k         70             73 != _int68
                     293k         71        F    76  = _int133
                     294k         85        F   113  = _int134
                     295k         85            145 != _int28
                     296k         85        F   140  = _int99
                     297k         96        F   341  = _int18
                     298k         93            212 != _int72
                     299k         88        F   122  = _int130
                     300k         86              0  = _int83
 ! Time = 2.30s, Average fail depth = 62, Memory usage = 11.2 MB
 !               Branches  Non-fixed            Branch decision
                     301k         89        F   240  = _int6
                     302k         68        F   156  = _int102
                     303k         66            163  = _int109
                     304k         75              0  = _int98
                     305k         52            117 != _int103
                     306k         89            187 != _int32
                     307k         86             49 != _int14
                     308k         65        F   190  = _int129
                     309k         74             61  = _int101
                     310k         61        F    64  = _int0
                     311k         27            157 != _int86
                     312k         56            287 != _int24
                     313k         45        F    24  = _int0
                     314k         45            257 != _int135
                     315k         45        F    24  = _int31
                     316k         45        F    99  = _int79
                     317k         23            306 != _int102
                     318k         55            164 != _int117
                     319k         62             87 != _int80
                     320k         70        F   119  = _int71
 ! Time = 2.45s, Average fail depth = 61, Memory usage = 10.4 MB
 !               Branches  Non-fixed            Branch decision
                     321k         72              9 != _int71
                     322k         47        F   296  = _int99
                     323k         84            291 != _int99
                     324k         85        F   293  = _int99
                     325k         89                 -
                     326k         88            153 != _int22
                     327k         90        F    54  = _int13
                     328k         84            397 != _int132
                     329k         86        F   375  = _int132
                     330k         83            364 != _int114
                     331k         86            445 != _int123
                     332k         88            347 != _int123
                     333k         74            129 != _int112
                     334k         76        F    69  = _int112
                     335k         78            133 != _int109
                     336k         64             50 != _int67
                     337k         65            158 != _int68
                     338k         67        F   159  = _int68
                     339k         57              6 != _int64
                     340k         57        F    81  = _int65
 ! Time = 2.59s, Average fail depth = 62, Memory usage = 10.4 MB
 !               Branches  Non-fixed            Branch decision
                     341k         58        F   106  = _int64
                     342k         54        F    45  = _int7
                     343k         50             25 != _int121
                     344k         52             80 != _int122
                     345k         53        F    14  = _int122
                     346k         37        F    45  = _int101
                     347k         57            322 != _int129
                     348k         36        F   132  = _int13
                     349k         52             34 != _int102
                     350k         38              0 != _int13
                     351k         38        F   234  = _int123
                     352k         44        F   413  = _int78
                     353k         44        F     4  = _int79
                     354k         83        F   417  = _int81
                     355k         83        F   127  = _int130
                     356k         87             72 != _int130
                     357k         90             35 != _int129
                     358k         76            231 != _int129
                     359k         84        F   143  = _int27
                     360k         54             51 != _int132
 ! Time = 2.77s, Average fail depth = 62, Memory usage = 11.6 MB
 !               Branches  Non-fixed            Branch decision
                     361k         54            220 != _int24
                     362k         73        F    45  = _int70
                     363k         59        F   455  = _int123
                     364k         58            153 != _int74
                     365k         58            119 != _int73
                     366k         63            167  = _int148
                     367k         65             55 != _int48
                     368k         67            477  = _int48
                     369k         65            136 != _int112
                     370k         71        F   122  = _int83
                     371k         53        F    79  = _int10
                     372k         55             44 != _int10
                     373k         55            162 != _int11
                     374k         58             47 != _int10
                     375k         58            115  = _int68
                     376k         66        F     8  = _int67
                     377k         60            124 != _int68
                     378k         61        F   355  = _int66
                     379k         62        F   342  = _int66
                     380k         64              3 != _int66
 ! Time = 2.89s, Average fail depth = 62, Memory usage = 10.5 MB
 !               Branches  Non-fixed            Branch decision
                     381k         69            107 != _int22
                     382k         62            108 != _int17
                     383k         62        F    94  = _int17
                     384k         65             56 != _int17
                     385k         68            411 != _int120
                     386k         71        F   278  = _int129
                     387k         71             34 != _int129
                     388k         72            100 != _int99
                     389k         92        F   213  = _int99
                     390k         69            147 != _int3
                     391k         69        F    99  = _int137
                     392k         73        F     6  = _int35
                     393k         63              0  = _int103
                     394k         52            233  = _int132
                     395k         58            109 != _int31
                     396k         61        F    54  = _int32
                     397k         56        F   118  = _int73
                     398k         56             22 != _int79
                     399k         63            118 != _int76
                     400k         74            375 != _int33
 ! Time = 3.06s, Average fail depth = 62, Memory usage = 10.5 MB
 !               Branches  Non-fixed            Branch decision
                     401k         89        F   285  = _int102
                     402k         91        F    39  = _int102
                     403k         91        F   442  = _int102
                     404k         87             32 != _int101
                     405k         87             92 != _int101
                     406k         87            143 != _int130
                     407k         75            233 != _int27
                     408k         75            182 != _int27
                     409k         77        F    39  = _int27
                     410k         75             45 != _int81
                     411k         41            234  = _int21
                     412k         38            155 != _int123
                     413k         34        F    97  = _int24
                     414k         36            280 != _int78
                     415k         40        F   125  = _int8
                     416k         45            190 != _int4
                     417k         49        F     3  = _int25
                     418k         45            212 != _int18
                     419k         59             72 != _int111
                     420k         60            193 != _int99
 ! Time = 3.24s, Average fail depth = 62, Memory usage = 10.5 MB
 !               Branches  Non-fixed            Branch decision
                     421k         61             32 != _int120
                     422k         52        F   421  = _int117
                     423k         32        F   181  = _int126
                     424k         21             68 != _int102
                     425k         80              7 != _int102
                     426k         80        F    64  = _int102
                     427k         80        F    54  = _int102
                     428k         16        F    16  = _int1
                     429k         16        F    41  = _int74
                     430k         25        F    92  = _int70
                     431k          9            143 != _int29
                     432k         39        F    86  = _int83
                     433k         20        F   324  = _int96
                     434k         28        F   231  = _int24
                     435k         16             97 != _int71
                     436k         52            476 != _int129
                     437k         74        F   366  = _int24
                     438k         72             64 != _int22
                     439k         36            176 != _int1
                     440k         36        F   141  = _int140
 ! Time = 3.42s, Average fail depth = 63, Memory usage = 11.8 MB
 !               Branches  Non-fixed            Branch decision
                     441k         12        F   206  = _int96
                     442k         47              0  = _int13
                     443k         45        F   125  = _int96
                     444k         43            133 != _int67
                     445k         43             14 != _int16
                     446k         46            319 != _int18
                     447k         58        F   102  = _int109
                     448k         41            236 != _int96
                     449k         41             72 != _int66
 *                   449k  3.50s                 85  = _int42
 ! ----------------------------------------------------------------------------
 ! Search completed, 1 solution found.
 ! ----------------------------------------------------------------------------
 ! Number of branches     : 449950
 ! Number of fails        : 204560
 ! Total memory usage     : 13.1 MB (10.6 MB CP Optimizer + 2.5 MB Concert)
 ! Time spent in solve    : 3.50s (3.47s engine + 0.04s extraction)
 ! Search speed (br. / s) : 129968.2
 ! ----------------------------------------------------------------------------
=======SOLUCAO 3D (FINAL)=======
Item[0]:0 0 35
Item[1]:308 157 190
Item[2]:259 62 48
Item[3]:357 77 190
Item[4]:228 0 0
Item[5]:249 82 109
Item[6]:248 103 0
Item[7]:259 85 142
Item[8]:1 17 190
Item[9]:252 57 79
Item[10]:0 0 1
Item[11]:379 0 190
Item[12]:472 93 26
Item[13]:262 16 52
Item[14]:85 99 195
Item[15]:385 0 49
Item[16]:477 184 133
Item[17]:102 80 9
Item[18]:254 155 32
Item[19]:339 0 96
Item[20]:107 190 121
Item[21]:129 99 135
Item[22]:0 152 115
Item[23]:362 0 134
Item[24]:0 0 102
Item[25]:364 144 39
Item[26]:495 0 0
Item[27]:456 150 13
Item[28]:241 0 117
Item[29]:506 200 92
Item[30]:3 108 183
Item[31]:278 0 183
Item[32]:125 134 0
Item[33]:467 0 75
Item[34]:112 0 68
Item[35]:13 154 172
Item[36]:365 163 132
Item[37]:1 80 51
Item[38]:476 109 121
Item[39]:476 115 72
Item[40]:0 163 52
Item[41]:14 156 0
Item[42]:1 82 100
Item[43]:242 52 172
Item[44]:233 161 117
Item[45]:259 145 58
Item[46]:0 84 0
Item[47]:14 84 149
Item[48]:2 0 159
Item[49]:2 0 66
================================
TIME: 3.513
STATUS: 1
Morrendo
Tentando empacotar!
W 587 H 233 L 220
Item[0]:49, 25, 21
Item[1]:49, 25, 21
Item[2]:49, 25, 21
Item[3]:49, 25, 21
Item[4]:49, 25, 21
Item[5]:49, 25, 21
Item[6]:49, 25, 21
Item[7]:49, 25, 21
Item[8]:49, 25, 21
Item[9]:49, 25, 21
Item[10]:49, 25, 21
Item[11]:49, 25, 21
Item[12]:49, 25, 21
Item[13]:49, 25, 21
Item[14]:49, 25, 21
Item[15]:49, 25, 21
Item[16]:49, 25, 21
Item[17]:49, 25, 21
Item[18]:49, 25, 21
Item[19]:49, 25, 21
Item[20]:49, 25, 21
Item[21]:60, 51, 41
Item[22]:60, 51, 41
Item[23]:60, 51, 41
Item[24]:60, 51, 41
Item[25]:60, 51, 41
Item[26]:60, 51, 41
Item[27]:60, 51, 41
Item[28]:60, 51, 41
Item[29]:60, 51, 41
Item[30]:60, 51, 41
Item[31]:60, 51, 41
Item[32]:60, 51, 41
Item[33]:60, 51, 41
Item[34]:60, 51, 41
Item[35]:60, 51, 41
Item[36]:60, 51, 41
Item[37]:60, 51, 41
Item[38]:60, 51, 41
Item[39]:60, 51, 41
Item[40]:60, 51, 41
Item[41]:60, 51, 41
Item[42]:60, 51, 41
Item[43]:60, 51, 41
Item[44]:103, 76, 64
Item[45]:103, 76, 64
Item[46]:103, 76, 64
Item[47]:103, 76, 64
Item[48]:103, 76, 64
Item[49]:103, 76, 64
Item[50]:103, 76, 64
Item[51]:103, 76, 64
Item[52]:103, 76, 64
Item[53]:103, 76, 64
Item[54]:103, 76, 64
Item[55]:103, 76, 64
Item[56]:103, 76, 64
Item[57]:103, 76, 64
iniciando os testes...
 ! --------------------------------------------------- CP Optimizer 22.1.1.0 --
 ! Satisfiability problem - 174 variables, 1653 constraints
 ! TimeLimit            = 1800
 ! Workers              = 1
 ! Initial process time : 0.06s (0.06s extraction + 0.00s propagation)
 !  . Log search space  : 1395.4 (before), 1395.4 (after)
 !  . Memory usage      : 2.0 MB (before), 2.0 MB (after)
 ! Using sequential search.
 ! ----------------------------------------------------------------------------
 !               Branches  Non-fixed            Branch decision
                     1000         20        F    94  = _int158
                     2000         20            244  = _int6
                     3000         49            273 != _int123
                     4000         55             79 != _int61
                     5000         49        F   132  = _int149
                     6000         54            261 != _int156
                     7000         98             60 != _int109
                     8000         56        F    37  = _int114
                     9000         42        F   376  = _int162
                    10000         41        F   170  = _int123
                    11000         41        F   125  = _int63
                    12000         50            134 != _int44
                    13000         42            144 != _int163
                    14000         57              2 != _int115
                    15000         36        F   306  = _int147
                    16000         52        F   135  = _int23
                    17000         53            311  = _int63
                    18000         40             98 != _int163
                    19000         58              0  = _int107
                    20000         60        F    14  = _int90
 ! Time = 0.27s, Average fail depth = 54, Memory usage = 11.5 MB
 !               Branches  Non-fixed            Branch decision
                    21000         92              0  = _int154
                    22000         29             53 != _int74
 *                  22467  0.29s                532  = _int39
 ! ----------------------------------------------------------------------------
 ! Search completed, 1 solution found.
 ! ----------------------------------------------------------------------------
 ! Number of branches     : 22467
 ! Number of fails        : 9309
 ! Total memory usage     : 14.9 MB (11.6 MB CP Optimizer + 3.2 MB Concert)
 ! Time spent in solve    : 0.29s (0.24s engine + 0.06s extraction)
 ! Search speed (br. / s) : 96424.9
 ! ----------------------------------------------------------------------------
=======SOLUCAO 3D (FINAL)=======
Item[0]:531 70 44
Item[1]:426 197 78
Item[2]:329 185 152
Item[3]:0 177 165
Item[4]:272 70 79
Item[5]:269 28 92
Item[6]:528 11 28
Item[7]:429 127 18
Item[8]:531 129 92
Item[9]:368 0 2
Item[10]:270 44 67
Item[11]:272 65 101
Item[12]:305 203 25
Item[13]:532 139 2
Item[14]:286 87 24
Item[15]:512 180 87
Item[16]:131 184 74
Item[17]:249 136 26
Item[18]:318 122 111
Item[19]:0 187 39
Item[20]:403 96 74
Item[21]:478 104 49
Item[22]:0 6 0
Item[23]:337 9 109
Item[24]:335 52 1
Item[25]:193 19 127
Item[26]:417 54 145
Item[27]:15 0 167
Item[28]:439 11 101
Item[29]:11 73 170
Item[30]:374 115 174
Item[31]:118 121 85
Item[32]:427 76 97
Item[33]:5 1 48
Item[34]:505 46 73
Item[35]:66 0 0
Item[36]:489 165 38
Item[37]:510 145 116
Item[38]:84 146 145
Item[39]:419 0 152
Item[40]:98 47 160
Item[41]:521 93 131
Item[42]:514 111 175
Item[43]:226 37 8
Item[44]:289 29 152
Item[45]:318 124 32
Item[46]:479 13 144
Item[47]:166 3 60
Item[48]:213 157 156
Item[49]:403 128 101
Item[50]:183 75 152
Item[51]:44 24 93
Item[52]:22 60 8
Item[53]:322 2 42
Item[54]:126 96 19
Item[55]:425 28 7
Item[56]:201 125 84
Item[57]:13 117 80
================================
TIME: 0.294
STATUS: 1
Morrendo
Tentando empacotar!
W 587 H 233 L 220
Item[0]:97, 81, 27
Item[1]:97, 81, 27
Item[2]:97, 81, 27
Item[3]:97, 81, 27
Item[4]:97, 81, 27
Item[5]:97, 81, 27
Item[6]:97, 81, 27
Item[7]:97, 81, 27
Item[8]:97, 81, 27
Item[9]:97, 81, 27
Item[10]:97, 81, 27
Item[11]:97, 81, 27
Item[12]:97, 81, 27
Item[13]:97, 81, 27
Item[14]:97, 81, 27
Item[15]:97, 81, 27
Item[16]:97, 81, 27
Item[17]:97, 81, 27
Item[18]:97, 81, 27
Item[19]:97, 81, 27
Item[20]:97, 81, 27
Item[21]:97, 81, 27
Item[22]:97, 81, 27
Item[23]:97, 81, 27
Item[24]:97, 81, 27
Item[25]:97, 81, 27
Item[26]:97, 81, 27
Item[27]:302, 78, 39
Item[28]:302, 78, 39
Item[29]:302, 78, 39
Item[30]:113, 200, 36
Item[31]:113, 200, 36
Item[32]:113, 200, 36
Item[33]:113, 200, 36
Item[34]:113, 200, 36
Item[35]:66, 50, 42
Item[36]:66, 50, 42
Item[37]:66, 50, 42
Item[38]:66, 50, 42
Item[39]:66, 50, 42
Item[40]:66, 50, 42
Item[41]:66, 50, 42
Item[42]:66, 50, 42
Item[43]:66, 50, 42
Item[44]:66, 50, 42
Item[45]:66, 50, 42
Item[46]:66, 50, 42
Item[47]:66, 50, 42
Item[48]:66, 50, 42
Item[49]:66, 50, 42
Item[50]:66, 50, 42
Item[51]:66, 50, 42
Item[52]:101, 130, 26
Item[53]:101, 130, 26
Item[54]:101, 130, 26
Item[55]:101, 130, 26
Item[56]:101, 130, 26
Item[57]:101, 130, 26
iniciando os testes...
Item largo: 27 
Item largo: 28 
Item largo: 29 
Item alto: 30 
Item alto: 31 
Item alto: 32 
Item alto: 33 
Item alto: 34 
Item alto: 52 
Item alto: 53 
Item alto: 54 
Item alto: 55 
Item alto: 56 
Item alto: 57 
 ! --------------------------------------------------- CP Optimizer 22.1.1.0 --
 ! Satisfiability problem - 6 variables, 3 constraints
 ! TimeLimit            = 600
 ! Workers              = 1
 ! Initial process time : 0.01s (0.01s extraction + 0.00s propagation)
 !  . Log search space  : 44.4 (before), 44.4 (after)
 !  . Memory usage      : 267.1 kB (before), 267.1 kB (after)
 ! Using sequential search.
 ! ----------------------------------------------------------------------------
 !               Branches  Non-fixed            Branch decision
 *                      7  0.01s                 80  = _int5
 ! ----------------------------------------------------------------------------
 ! Search completed, 1 solution found.
 ! ----------------------------------------------------------------------------
 ! Number of branches     : 7
 ! Number of fails        : 0
 ! Total memory usage     : 697.2 kB (653.5 kB CP Optimizer + 43.7 kB Concert)
 ! Time spent in solve    : 0.01s (0.00s engine + 0.01s extraction)
 ! Search speed (br. / s) : 700.0
 ! ----------------------------------------------------------------------------
=======SOLUCAO 2D=======
Item[0]:43 163
Item[1]:122 42
Item[2]:26 80
========================
 ! --------------------------------------------------- CP Optimizer 22.1.1.0 --
 ! Satisfiability problem - 22 variables, 55 constraints
 ! TimeLimit            = 600
 ! Workers              = 1
 ! Initial process time : 0.01s (0.01s extraction + 0.00s propagation)
 !  . Log search space  : 181.3 (before), 181.3 (after)
 !  . Memory usage      : 332.9 kB (before), 332.9 kB (after)
 ! Using sequential search.
 ! ----------------------------------------------------------------------------
 !               Branches  Non-fixed            Branch decision
 *                    466  0.01s                192  = _int11
 ! ----------------------------------------------------------------------------
 ! Search completed, 1 solution found.
 ! ----------------------------------------------------------------------------
 ! Number of branches     : 466
 ! Number of fails        : 208
 ! Total memory usage     : 1.1 MB (1.0 MB CP Optimizer + 0.1 MB Concert)
 ! Time spent in solve    : 0.01s (0.01s engine + 0.01s extraction)
 ! Search speed (br. / s) : 46600.0
 ! ----------------------------------------------------------------------------
=======SOLUCAO 2D=======
Item[0]:44 112
Item[1]:233 134
Item[2]:25 72
Item[3]:3 152
Item[4]:401 159
Item[5]:48 192
Item[6]:228 20
Item[7]:150 83
Item[8]:220 55
Item[9]:257 82
Item[10]:12 28
========================
 ! --------------------------------------------------- CP Optimizer 22.1.1.0 --
 ! Satisfiability problem - 174 variables, 1653 constraints
 ! TimeLimit            = 1800
 ! Workers              = 1
 ! Initial process time : 0.06s (0.06s extraction + 0.00s propagation)
 !  . Log search space  : 1366.9 (before), 1366.9 (after)
 !  . Memory usage      : 1.9 MB (before), 1.9 MB (after)
 ! Using sequential search.
 ! ----------------------------------------------------------------------------
 !               Branches  Non-fixed            Branch decision
                     1000         57            403  = _int102
                     2000         55        F   176  = _int149
                     3000         68              0  = _int134
                     4000         58            268 != _int81
                     5000         68        F    80  = _int81
                     6000         49        F   151  = _int83
                     7000         86             20 != _int47
                     8000         48        F   297  = _int138
                     9000         45        F    14  = _int47
                    10000         56             54 != _int61
                    11000         56        F    68  = _int88
                    12000         71              0  = _int94
                    13000         52            156 != _int127
                    14000         48            155 != _int164
                    15000         53             78 != _int98
                    16000         56              0  = _int130
                    17000         55            182 != _int153
                    18000         53        F    12  = _int114
                    19000         52            199 != _int162
                    20000         51        F   120  = _int65
 ! Time = 0.23s, Average fail depth = 58, Memory usage = 12.8 MB
 !               Branches  Non-fixed            Branch decision
                    21000         51              0  = _int114
                    22000         52            174  = _int5
                    23000         83              0  = _int23
                    24000         57                 -
                    25000         48             89 != _int49
                    26000         57            313 != _int90
                    27000         27            151  = _int87
                    28000         26        F   213  = _int57
                    29000         57            141 != _int106
                    30000        117        F    93  = _int106
                    31000         57             33 != _int19
                    32000         91            276 != _int12
                    33000         56             97 != _int28
                    34000         57            329 != _int90
                    35000         57        F     3 != _int25
                    36000         63            378 != _int1
                    37000         63            120 != _int19
                    38000        101        F     5  = _int67
                    39000         57            144 != _int28
                    40000         61        F   110  = _int143
 ! Time = 0.36s, Average fail depth = 69, Memory usage = 11.6 MB
 !               Branches  Non-fixed            Branch decision
                    41000         57            365 != _int36
                    42000         74        F     4  = _int68
                    43000         57            306 != _int90
                    44000         57            335 != _int60
                    45000         37             37 != _int148
                    46000         35        F   185  = _int81
                    47000         74        F   146  = _int81
                    48000         57        F   306  = _int90
                    49000         57        F   114  = _int52
                    50000         40            465 != _int159
                    51000         57            121 != _int88
                    52000         56            183  = _int130
                    53000         55             82 != _int121
                    54000         53        F    52  = _int154
                    55000         56            161 != _int146
                    56000         87            103 != _int8
                    57000         84        F   194  = _int87
                    58000         86        F   110  = _int71
                    59000         89            332 != _int102
                    60000         73              0  = _int49
 ! Time = 0.55s, Average fail depth = 77, Memory usage = 13.9 MB
 !               Branches  Non-fixed            Branch decision
                    61000         73            137 != _int65
                    62000         73            103  = _int85
                    63000         41            103  = _int85
                    64000         48        F   107  = _int17
                    65000         50        F   150  = _int154
                    66000         62        F   173  = _int98
                    67000         41        F    20  = _int46
                    68000         41        F   428  = _int6
                    69000         69            108 != _int133
                    70000         69            410 != _int123
                    71000         79              0  = _int19
                    72000         62            163 != _int118
                    73000         43            187 != _int57
                    74000         30        F    30  = _int1
                    75000         29        F   153  = _int11
                    76000         30             37 != _int10
                    77000         67        F   150  = _int43
                    78000         51            123  = _int153
                    79000         25             12 != _int53
                    80000         20        F    15  = _int121
 ! Time = 0.79s, Average fail depth = 88, Memory usage = 12.1 MB
 !               Branches  Non-fixed            Branch decision
                    81000         27        F    44  = _int92
                    82000         25        F    37  = _int76
                    83000         25            328 != _int96
                    84000         32        F     4  = _int52
                    85000         32        F    25  = _int89
                    86000         35             65 != _int113
                    87000         35        F   122  = _int83
                    88000         37        F    82  = _int41
                    89000         35        F   188  = _int81
                    90000         95             61 != _int93
                    91000         26                 -
                    92000         62             44 != _int148
                    93000         52        F   444  = _int51
                    94000         40             47 != _int137
                    95000         23        F   144  = _int22
                    96000         23            460 != _int45
                    97000        109            340 != _int93
                    98000         66        F    83  = _int90
                    99000         66             20 != _int92
                     100k         86        F    91  = _int78
 ! Time = 0.96s, Average fail depth = 88, Memory usage = 13.8 MB
 !               Branches  Non-fixed            Branch decision
                     101k         54        F   308  = _int102
                     102k         49        F    28  = _int90
                     103k         40             63  = _int149
                     104k         35        F   325  = _int162
                     105k         35        F    87  = _int136
                     106k         50        F   192  = _int170
                     107k         44             79 != _int88
                     108k         40        F   119  = _int171
                     109k         33             71 != _int28
                     110k         33        F    56  = _int158
                     111k         32              1  = _int39
                     112k         63            307  = _int162
                     113k         43        F   143  = _int60
                     114k         45        F    89  = _int121
                     115k         25        F    79  = _int5
                     116k         25            125  = _int161
                     117k         61             78 != _int23
                     118k         62        F    60  = _int98
                     119k         53        F   135  = _int146
                     120k         43        F    52  = _int123
 ! Time = 1.11s, Average fail depth = 87, Memory usage = 12.6 MB
 !               Branches  Non-fixed            Branch decision
                     121k         43              0  = _int28
                     122k         36            217 != _int129
                     123k         30        F    70  = _int155
                     124k         31            149 != _int154
                     125k         36              0  = _int5
                     126k        123             28 != _int96
                     127k        104            216 != _int84
                     128k         49            279 != _int162
                     129k         49        F   413  = _int162
                     130k         46             39 != _int74
                     131k         47            366 != _int102
                     132k         55             60 != _int8
                     133k         53             14 != _int172
                     134k         56        F    29  = _int81
                     135k         57            103  = _int139
                     136k         67            150 != _int58
                     137k         47             28 != _int76
                     138k         48            159  = _int68
                     139k         33            107 != _int13
                     140k         23        F   106  = _int125
 ! Time = 1.24s, Average fail depth = 90, Memory usage = 12.7 MB
 !               Branches  Non-fixed            Branch decision
                     141k         17        F   281  = _int171
                     142k         29            478  = _int39
                     143k         33             23 != _int92
                     144k         36        F    68  = _int92
                     145k         24              0  = _int101
                     146k         33            153  = _int108
                     147k         19            167 != _int101
                     148k         49            136 != _int86
                     149k         54             91 != _int19
                     150k         54        F    87  = _int7
                     151k         39            176 != _int95
                     152k         40        F   332  = _int93
                     153k        142        F   449  = _int93
                     154k         63            226 != _int114
                     155k         59            361 != _int153
                     156k         59            184 != _int44
                     157k         40            219 != _int60
                     158k         40        F    81  = _int65
                     159k         75            425 != _int159
                     160k         60            361 != _int78
 ! Time = 1.41s, Average fail depth = 90, Memory usage = 15.0 MB
 !               Branches  Non-fixed            Branch decision
                     161k         31             49  = _int158
                     162k         55        F    32  = _int28
                     163k         55             83 != _int40
                     164k         47        F   171  = _int149
                     165k         36            278  = _int147
                     166k         42        F   141  = _int144
                     167k         45        F    48  = _int11
                     168k         36        F   210  = _int162
                     169k         49        F    47  = _int68
                     170k         34            287 != _int150
                     171k         51        F   261  = _int159
                     172k         43        F    59  = _int140
                     173k         40        F   133  = _int77
                     174k         14        F   293  = _int0
                     175k         14            300 != _int96
                     176k         29            493 != _int126
                     177k         28            152  = _int13
                     178k         23        F    83  = _int4
                     179k         34             44 != _int64
                     180k         20              3 != _int92
 ! Time = 1.57s, Average fail depth = 87, Memory usage = 15.1 MB
 !               Branches  Non-fixed            Branch decision
                     181k         27            179 != _int83
                     182k         33        F    17  = _int0
                     183k         25        F   196  = _int36
                     184k         25             15 != _int36
                     185k         26             18 != _int133
                     186k         26             31 != _int118
                     187k         26             17 != _int142
                     188k         26        F    63  = _int109
                     189k         30        F    38  = _int67
                     190k         35             17 != _int67
                     191k         38        F   243  = _int81
                     192k        109        F    83  = _int81
                     193k         83        F   135  = _int159
                     194k         80        F   196  = _int96
                     195k         81            146 != _int96
                     196k         17        F    52  = _int36
                     197k        100             67 != _int36
                     198k         55        F    82  = _int144
                     199k         31            116 != _int87
                     200k         31             32 != _int87
 ! Time = 1.77s, Average fail depth = 89, Memory usage = 13.1 MB
 !               Branches  Non-fixed            Branch decision
                     201k         31            155 != _int105
                     202k         16             58 != _int153
                     203k         16        F   380  = _int153
                     204k          8             73 != _int26
                     205k          8             67 != _int26
                     206k          8            238 != _int39
                     207k         50        F   302  = _int51
                     208k         50            105  = _int96
                     209k         75        F   159  = _int143
                     210k         58            451 != _int6
                     211k         90        F   127  = _int40
                     212k         72        F     0  = _int0
                     213k         61        F   103  = _int19
                     214k         58             67 != _int64
                     215k         49             19  = _int172
                     216k         50             36 != _int148
                     217k         49        F   365  = _int0
                     218k         27             67 != _int59
                     219k         31        F    36  = _int47
                     220k         83        F    71  = _int171
 ! Time = 1.94s, Average fail depth = 91, Memory usage = 15.1 MB
 !               Branches  Non-fixed            Branch decision
                     221k         75             36 != _int157
                     222k         48             54  = _int146
                     223k         62             32 != _int22
                     224k         49        F   121  = _int149
                     225k         69            115  = _int17
                     226k         53            333 != _int0
                     227k         20            373 != _int162
                     228k         20             27 != _int16
                     229k         42        F   105  = _int156
                     230k         42        F    22  = _int27
                     231k         42        F   105  = _int112
                     232k         52        F     5  = _int112
                     233k         40        F    71  = _int69
                     234k         40        F    62  = _int69
                     235k         40        F   500  = _int144
                     236k         22        F    28  = _int25
                     237k         25             35 != _int25
                     238k         28             28 != _int75
                     239k         93        F   131  = _int75
                     240k         62            177 != _int45
 ! Time = 2.07s, Average fail depth = 92, Memory usage = 13.4 MB
 !               Branches  Non-fixed            Branch decision
                     241k         62             89 != _int45
                     242k         64            176 != _int164
                     243k         68            161 != _int164
                     244k         68            117  = _int162
                     245k         68        F    77  = _int84
                     246k         69        F    77  = _int84
                     247k         75            212  = _int93
                     248k         72             94 != _int36
                     249k         73             60 != _int27
                     250k         67            143 != _int39
                     251k         63            144 != _int136
                     252k         65        F    91  = _int136
                     253k         66        F   442  = _int96
                     254k         70            465 != _int96
                     255k         55        F   179  = _int118
                     256k         55        F    41  = _int118
                     257k         39        F   179  = _int35
                     258k         40            151 != _int35
                     259k         43            115 != _int34
                     260k         46            121 != _int34
 ! Time = 2.25s, Average fail depth = 93, Memory usage = 13.4 MB
 !               Branches  Non-fixed            Branch decision
                     261k         48        F    88  = _int34
                     262k         51        F   278  = _int6
                     263k         66            340 != _int6
                     264k         67        F   345  = _int6
                     265k         63        F   116  = _int10
                     266k         64             11 != _int10
                     267k         47            164  = _int141
                     268k         15            173 != _int68
                     269k         11        F     3  = _int64
                     270k         11        F   151  = _int47
                     271k         35        F   155  = _int69
                     272k         12        F     4  = _int23
                     273k         12             59 != _int79
                     274k         14            109 != _int92
                     275k          6             14 != _int25
                     276k         19        F    45  = _int69
                     277k         19        F    88  = _int76
                     278k         31        F   129  = _int40
                     279k         31            392 != _int9
                     280k         20        F    70  = _int65
 ! Time = 2.40s, Average fail depth = 92, Memory usage = 13.5 MB
 !               Branches  Non-fixed            Branch decision
                     281k         14             50 != _int58
                     282k         31        F   107  = _int86
                     283k         71            233 != _int150
                     284k         29            113 != _int41
                     285k          9        F   119  = _int26
                     286k          9            140 != _int25
                     287k         26             47 != _int65
                     288k         27        F    89  = _int47
                     289k         27              0  = _int143
                     290k         15              0 != _int92
                     291k         16        F    35  = _int81
                     292k          8        F    50  = _int26
                     293k         13             98 != _int170
                     294k         26            486  = _int78
                     295k         60        F    68  = _int55
                     296k         64        F     4  = _int55
                     297k         70        F   143  = _int87
                     298k         50        F    59  = _int19
                     299k         50        F   157  = _int57
                     300k         65        F   142  = _int14
 ! Time = 2.55s, Average fail depth = 91, Memory usage = 15.2 MB
 !               Branches  Non-fixed            Branch decision
                     301k          6            456  = _int0
                     302k         22             81  = _int130
                     303k         13        F   320  = _int96
                     304k         10        F   321  = _int9
                     305k         25        F   457  = _int6
                     306k         17        F   189  = _int26
                     307k         12        F   110  = _int71
                     308k         23            223 != _int105
                     309k         33        F   123  = _int98
                     310k         37            415 != _int159
                     311k         37            152 != _int78
                     312k         58        F   278  = _int93
                     313k         43            408 != _int39
                     314k         60            413 != _int75
                     315k         59            216 != _int12
                     316k         32        F    56  = _int50
                     317k         51            202 != _int150
                     318k         57        F    25  = _int7
                     319k         35            334  = _int96
                     320k         64            419 != _int6
 ! Time = 2.70s, Average fail depth = 90, Memory usage = 13.6 MB
 !               Branches  Non-fixed            Branch decision
                     321k         94        F   165  = _int69
                     322k         95            378 != _int69
                     323k         98        F   261  = _int69
                     324k         89            359 != _int150
                     325k         89        F   127  = _int150
                     326k         90             66 != _int95
                     327k         20            159 != _int139
                     328k         20        F   176  = _int142
                     329k         21            350  = _int78
                     330k         21            157 != _int105
                     331k         43        F   407  = _int105
                     332k         44        F    79  = _int37
                     333k         59             97 != _int37
                     334k         57        F   365  = _int162
                     335k         57            451 != _int162
                     336k         60        F   420  = _int162
                     337k         62              4 != _int73
                     338k         62        F    59  = _int73
                     339k         55        F   130  = _int36
                     340k         57        F    99  = _int36
 ! Time = 2.98s, Average fail depth = 92, Memory usage = 13.7 MB
 !               Branches  Non-fixed            Branch decision
                     341k         61             47 != _int36
                     342k         44            303 != _int0
                     343k         44            352 != _int0
                     344k         44        F    89  = _int148
                     345k         50            156  = _int95
                     346k         85            315 != _int150
                     347k         85        F   517  = _int150
                     348k         86            341 != _int150
                     349k         87            137 != _int150
                     350k         68            201 != _int99
                     351k         72            345  = _int0
                     352k         80             78  = _int89
                     353k         41             64 != _int149
                     354k         55        F   124  = _int11
                     355k         58            112 != _int98
                     356k         46        F   342  = _int45
                     357k         46        F    27  = _int52
                     358k         30              6  = _int97
                     359k         65            193  = _int23
                     360k         31            109 != _int88
 ! Time = 3.22s, Average fail depth = 92, Memory usage = 15.9 MB
 !               Branches  Non-fixed            Branch decision
                     361k         53        F    66  = _int28
                     362k         53        F   165  = _int90
                     363k         62            113 != _int104
                     364k         45            138 != _int146
                     365k         40              6  = _int89
                     366k         40        F     6  = _int172
                     367k        121             53 != _int172
                     368k         73        F    90  = _int49
                     369k         75             65 != _int49
                     370k         78            144 != _int49
                     371k         73             25 != _int17
                     372k         64             83 != _int7
                     373k         67        F    38  = _int7
                     374k         70             72 != _int7
                     375k         54             31 != _int69
                     376k         54        F    41  = _int69
                     377k         53        F   116  = _int9
                     378k         53            253 != _int9
                     379k         56            375 != _int9
                     380k         58            241 != _int9
 ! Time = 3.40s, Average fail depth = 92, Memory usage = 13.8 MB
 !               Branches  Non-fixed            Branch decision
                     381k         60            197 != _int39
                     382k         72        F   193  = _int39
                     383k         73            457 != _int39
                     384k         45            253 != _int147
                     385k         20             92 != _int5
                     386k         20            133 != _int44
                     387k         21            123 != _int44
                     388k         21             83 != _int5
                     389k         29        F   326  = _int102
                     390k         67            258 != _int87
                     391k         56            193  = _int4
                     392k         70             47  = _int92
                     393k         60            151 != _int55
                     394k         47            227 != _int171
                     395k         50        F    58  = _int85
                     396k         57            103 != _int43
                     397k         57        F    28  = _int78
                     398k         61        F    81  = _int47
                     399k         38            216 != _int45
                     400k         55            169 != _int98
 ! Time = 3.56s, Average fail depth = 93, Memory usage = 15.7 MB
 !               Branches  Non-fixed            Branch decision
                     401k         65            150  = _int31
                     402k         46            117  = _int136
                     403k         40            469 != _int57
                     404k         38            176 != _int107
                     405k         14        F    68  = _int22
                     406k         43            122 != _int23
                     407k         38            424  = _int1
                     408k         30        F    78  = _int109
                     409k         30            138 != _int80
                     410k         51            108 != _int65
                     411k         37        F    91  = _int16
                     412k         41            114 != _int4
                     413k         33        F    30  = _int14
                     414k         35        F   123  = _int14
                     415k         31        F    44  = _int74
                     416k         31             55 != _int74
                     417k         34              8 != _int74
                     418k         36        F   167  = _int74
                     419k         37        F    49  = _int67
                     420k         43            141 != _int67
 ! Time = 3.69s, Average fail depth = 93, Memory usage = 13.9 MB
 !               Branches  Non-fixed            Branch decision
                     421k         46        F    60  = _int67
                     422k         49        F    23  = _int67
                     423k         20            261 != _int84
                     424k         22        F   160  = _int84
                     425k         25            213 != _int84
                     426k         29            190  = _int158
                     427k         83        F   135  = _int46
                     428k         86             60 != _int46
                     429k         75            113 != _int89
                     430k         73            421 != _int99
                     431k         75        F   472  = _int99
                     432k         78            406 != _int99
                     433k         74        F   290  = _int0
                     434k         74             28 != _int15
                     435k         78        F   242  = _int15
                     436k         79            219 != _int15
                     437k         80              8 != _int15
                     438k         14        F   192  = _int8
                     439k         13            167 != _int32
                     440k         11             28 != _int47
 ! Time = 3.90s, Average fail depth = 94, Memory usage = 13.9 MB
 !               Branches  Non-fixed            Branch decision
                     441k         23        F    94  = _int67
                     442k         19            159  = _int68
                     443k         27             96 != _int23
                     444k         14        F    67  = _int64
                     445k         19             51 != _int49
                     446k         21              0  = _int46
                     447k         46        F   325  = _int57
                     448k         45            166 != _int170
                     449k         38            234 != _int42
                     450k         42        F   395  = _int45
                     451k         60             94 != _int13
                     452k         17        F   210  = _int141
                     453k         12              0  = _int33
                     454k         10            146 != _int118
                     455k         13        F   150  = _int148
                     456k         22        F   107  = _int121
                     457k          6            119  = _int164
                     458k          6            135 != _int80
                     459k         12        F    91  = _int169
                     460k         32             58 != _int167
 ! Time = 4.05s, Average fail depth = 93, Memory usage = 16.2 MB
 !               Branches  Non-fixed            Branch decision
                     461k         14        F   118  = _int143
                     462k         12        F    93  = _int167
                     463k         34            355 != _int96
                     464k         42        F   289  = _int96
                     465k         45        F   362  = _int96
 *                   465k  4.10s                239  = _int1
 ! ----------------------------------------------------------------------------
 ! Search completed, 1 solution found.
 ! ----------------------------------------------------------------------------
 ! Number of branches     : 465728
 ! Number of fails        : 202260
 ! Total memory usage     : 17.2 MB (14.0 MB CP Optimizer + 3.2 MB Concert)
 ! Time spent in solve    : 4.10s (4.04s engine + 0.06s extraction)
 ! Search speed (br. / s) : 115307.7
 ! ----------------------------------------------------------------------------
=======SOLUCAO 3D (FINAL)=======
Item[0]:345 73 53
Item[1]:239 0 193
Item[2]:99 56 157
Item[3]:141 0 193
Item[4]:0 0 162
Item[5]:368 150 193
Item[6]:121 0 53
Item[7]:338 68 193
Item[8]:330 0 0
Item[9]:490 0 117
Item[10]:386 130 0
Item[11]:0 0 193
Item[12]:451 5 15
Item[13]:5 151 171
Item[14]:245 152 193
Item[15]:377 0 151
Item[16]:366 127 96
Item[17]:104 0 84
Item[18]:106 141 186
Item[19]:490 0 88
Item[20]:393 0 88
Item[21]:0 45 114
Item[22]:112 151 155
Item[23]:393 0 124
Item[24]:474 1 42
Item[25]:228 16 119
Item[26]:486 3 191
Item[27]:0 154 0
Item[28]:188 154 39
Item[29]:0 74 6
Item[30]:0 3 47
Item[31]:212 5 156
Item[32]:241 25 81
Item[33]:113 31 113
Item[34]:474 7 152
Item[35]:521 183 0
Item[36]:116 169 41
Item[37]:407 4 178
Item[38]:521 93 6
Item[39]:233 0 2
Item[40]:30 147 122
Item[41]:521 181 52
Item[42]:376 4 33
Item[43]:521 99 51
Item[44]:167 0 6
Item[45]:304 0 33
Item[46]:85 13 0
Item[47]:320 101 0
Item[48]:146 104 54
Item[49]:340 0 178
Item[50]:0 88 148
Item[51]:19 0 0
Item[52]:475 97 190
Item[53]:339 103 125
Item[54]:234 99 119
Item[55]:3 61 83
Item[56]:349 89 160
Item[57]:476 99 108
================================
TIME: 4.111
STATUS: 1
Morrendo
