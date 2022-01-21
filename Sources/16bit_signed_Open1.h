/**********************************************************************
* Written by WAVToCode
* Date:				Fri Dec 10 04:00:11 PM
* FileName:			16bit_signed_Open1.C
* Interleaved:		N/A
* Signed:			Yes
* No. of channels:	1
* No. of samples:	2173
* Bits/Sample:		16
**********************************************************************/


#define WAVE1_NUM_ELEMENTS 517
#define WAVE2_NUM_ELEMENTS 2173
#define WAVE3_NUM_ELEMENTS 220


const signed short wavedata3[WAVE3_NUM_ELEMENTS] = {
		0, 1423, 2817, 4154, 5406, 6549, 7557, 8413, 9096, 9595, 9898, 10000, 9898,
		9595, 9096, 8413, 7557, 6549, 5406, 4154, 2817, 1423, 0, -1423, -2817, -4154,
		 -5406, -6549, -7557, -8413, -9096, -9595, -9898, -10000, -9898, -9595, -9096,
		 -8413, -7557, -6549, -5406, -4154, -2817, -1423,
		 0, 1423, 2817, 4154, 5406, 6549, 7557, 8413, 9096, 9595, 9898, 10000, 9898,
		 		9595, 9096, 8413, 7557, 6549, 5406, 4154, 2817, 1423, 0, -1423, -2817, -4154,
		 		 -5406, -6549, -7557, -8413, -9096, -9595, -9898, -10000, -9898, -9595, -9096,
		 		 -8413, -7557, -6549, -5406, -4154, -2817, -1423,
		 0, 1423, 2817, 4154, 5406, 6549, 7557, 8413, 9096, 9595, 9898, 10000, 9898,
				9595, 9096, 8413, 7557, 6549, 5406, 4154, 2817, 1423, 0, -1423, -2817, -4154,
				 -5406, -6549, -7557, -8413, -9096, -9595, -9898, -10000, -9898, -9595, -9096,
				 -8413, -7557, -6549, -5406, -4154, -2817, -1423,
		 0, 1423, 2817, 4154, 5406, 6549, 7557, 8413, 9096, 9595, 9898, 10000, 9898,
						9595, 9096, 8413, 7557, 6549, 5406, 4154, 2817, 1423, 0, -1423, -2817, -4154,
						 -5406, -6549, -7557, -8413, -9096, -9595, -9898, -10000, -9898, -9595, -9096,
						 -8413, -7557, -6549, -5406, -4154, -2817, -1423,
		 0, 1423, 2817, 4154, 5406, 6549, 7557, 8413, 9096, 9595, 9898, 10000, 9898,
						9595, 9096, 8413, 7557, 6549, 5406, 4154, 2817, 1423, 0, -1423, -2817, -4154,
						 -5406, -6549, -7557, -8413, -9096, -9595, -9898, -10000, -9898, -9595, -9096,
						 -8413, -7557, -6549, -5406, -4154, -2817, -1423,
};

const signed short wavedata2[WAVE2_NUM_ELEMENTS] = {//NUM_ELEMENTS
 91,  -6, -116, -160, -76, -429, -4251, -8519, /* 0-7 */
-7162, -164, 9050, 16111, 17742, 12715, 2345, -9993, /* 8-15 */
-20065, -24230, -20656, -10037, 4505, 18432, 27220, 27859, /* 16-23 */
19837, 5311, -11370, -25066, -31498, -28534, -16825, 275, /* 24-31 */
17678, 30090, -31923, 27035, 12207, -6481, -23400, 32052, /* 32-39 */
31851, -23855, -6921, 12111, 27642, -30440, 32225, 19783, /* 40-47 */
1444, -17361, -31061, 29975, -29515, -14750, 4259, 21913, /* 48-55 */
-32475, -31076, 25743, 9522, -9394, -25464, 31515, -32594, /* 56-63 */
-21601, -4326, 14165, 28431, -31272, 29945, 16817, -1146, /* 64-71 */
-18618, -30449, 32291, -26279, -11728, 6137, 22085, 31482, /* 72-79 */
31618, 22470, 6773, -10801, -25083, -31916, -29307, -18107, /* 80-87 */
-1690, 15068, 27235, 31288, 26173, 13531, -2898, -18356, /* 88-95 */
-28367, -30059, -22967, -9240, 7057, 21177, 29033, 28344, /* 96-103 */
19373, 4838, -10978, -23430, -28901, -25879, -15352, -448, /* 104-111 */
14434, 24922, 27973, 22779, 10989, -3836, -17280, -25471, /* 112-119 */
-26139, -19363, -7597, 5976, 17971, 25376, 25998, 19308, /* 120-127 */
6446, -9527, -22597, -28147, -24805, -14030, 597, 14660, /* 128-135 */
23979, 25929, 20160, 8529, -5385, -17329, -23905, -23297, /* 136-143 */
-15838, -3878, 8901, 18805, 23006, 20374, 11891,  47, /* 144-151 */
-11641, -19660, -21782, -17441, -8063, 3427, 13631, 19655, /* 152-159 */
19835, 14248, 4702, -6038, -14778, -19085, -17818, -11366, /* 160-167 */
-1694, 8279, 15658, 18344, 15521, 8252, -1269, -10176, /* 168-175 */
-15882, -16869, -12923, -5254, 3757, 11397, 15537, 15058, /* 176-183 */
10260, 2659, -5559, -11996, -14803, -13273, -7857, -317, /* 184-191 */
7073, 12248, 13765, 11242, 5544, -1598, -8111, -12075, /* 192-199 */
-12467, -9279, -3464, 3210, 8777, 11704, 11144, 7309, /* 200-207 */
1461, -4624, -9146, -10873, -9492, -5463,  14, 5360, /* 208-215 */
9069, 10147, 8319, 4119, -1198, -6146, -9220, -9578, /* 216-223 */
-7166, -2658, 2550, 6928, 9226, 8800, 5785, 1136, /* 224-231 */
-3775, -7539, -9005, -7832, -4403, 248, 4723, 7775, /* 232-239 */
8522, 6793, 3149, -1288, -5331, -7791, -7992, -5953, /* 240-247 */
-2181, 2217, 5948, 7915, 7540, 4963, 1041, -3120, /* 248-255 */
-6355, -7714, -6857, -4047, -100, 3789, 6512, 7346, /* 256-263 */
6062, 3081, -690, -4225, -6491, -6851, -5253, -2127, /* 264-271 */
1542, 4674, 6360, 6180, 4201, 1075, -2242, -4852, /* 272-279 */
-5959, -5338, -3254, -327, 2627, 4800, 5592, 4781, /* 280-287 */
2586, -310, -3089, -4941, -5278, -4114, -1798, 996, /* 288-295 */
3427, 4831, 4866, 3527, 1171, -1469, -3663, -4761, /* 296-303 */
-4478, -2938, -551, 1967, 3869, 4624, 4028, 2248, /* 304-311 */
-161, -2439, -3984, -4350, -3468, -1580, 749, 2772, /* 312-319 */
3981, 4054, 2986, 1049, -1179, -3111, -4139, -3882, /* 320-327 */
-2470, -320, 1870, 3442, 4009, 3446, 1860, -265, /* 328-335 */
-2243, -3559, -3841, -3003, -1319, 732, 2500, 3511, /* 336-343 */
3507, 2473, 725, -1163, -2638, -3309, -2969, -1795, /* 344-351 */
-145, 1473, 2559, 2873, 2358, 1172, -307, -1606, /* 352-359 */
-2377, -2405, -1729, -637, 615, 1641, 2124, 1958, /* 360-367 */
1229, 192, -818, -1547, -1846, -1574, -871,  39, /* 368-375 */
916, 1493, 1639, 1345, 666, -249, -1103, -1650, /* 376-383 */
-1699, -1159, -256, 736, 1497, 1737, 1460, 752, /* 384-391 */
-198, -1095, -1665, -1711, -1164, -232, 706, 1393, /* 392-399 */
1626, 1371, 710, -176, -994, -1475, -1482, -1037, /* 400-407 */
-257, 554, 1138, 1375, 1203, 729, 100, -572, /* 408-415 */
-1134, -1411, -1306, -812, -43, 763, 1414, 1635, /* 416-423 */
1325, 659, -192, -1003, -1522, -1617, -1256, -492, /* 424-431 */
430, 1252, 1728, 1622, 1007, 116, -830, -1528, /* 432-439 */
-1724, -1387, -637, 295, 1101, 1594, 1638, 1166, /* 440-447 */
321, -658, -1452, -1771, -1516, -804, 172, 1120, /* 448-455 */
1738, 1837, 1326, 373, -710, -1597, -2004, -1783, /* 456-463 */
-993, 115, 1215, 1918, 2001, 1507, 589, -489, /* 464-471 */
-1450, -2011, -1979, -1359, -334, 828, 1778, 2179, /* 472-479 */
1907, 1049, -90, -1157, -1865, -2021, -1576, -705, /* 480-487 */
296, 1172, 1716, 1771, 1311, 470, -478, -1211, /* 488-495 */
-1528, -1403, -890, -154, 568, 1089, 1269, 1100, /* 496-503 */
640,   8, -597, -1028, -1146, -896, -382, 201, /* 504-511 */
687, 905, 779, 455,  67, -267, -466, -510, /* 512-519 */
-423, -295, -145,  30, 224, 383, 471, 464, /* 520-527 */
301,  33, -246, -418, -438, -364, -224, -19, /* 528-535 */
191, 309, 333, 274, 160,  45, -64, -171, /* 536-543 */
-257, -283, -245, -127,  40, 179, 279, 297, /* 544-551 */
192,  28, -110, -196, -263, -295, -246, -93, /* 552-559 */
139, 367, 465, 388, 186, -86, -370, -543, /* 560-567 */
-514, -309,  39, 440, 705, 711, 435, -54, /* 568-575 */
-594, -949, -914, -513,  70, 630, 1005, 1051, /* 576-583 */
711, 126, -523, -1021, -1122, -807, -248, 354, /* 584-591 */
822, 1052, 944, 508, -109, -708, -1091, -1126, /* 592-599 */
-776, -153, 530, 1070, 1297, 1101, 513, -257, /* 600-607 */
-949, -1373, -1374, -941, -207, 630, 1274, 1479, /* 608-615 */
1237, 671, -57, -738, -1207, -1354, -1125, -598, /* 616-623 */
103, 794, 1262, 1365, 1038, 405, -318, -917, /* 624-631 */
-1248, -1233, -887, -320, 340, 931, 1281, 1294, /* 632-639 */
975, 368, -405, -1116, -1528, -1472, -966, -172, /* 640-647 */
675, 1323, 1596, 1411, 832,   9, -814, -1385, /* 648-655 */
-1578, -1334, -708, 106, 865, 1372, 1498, 1189, /* 656-663 */
542, -217, -877, -1279, -1294, -957, -443, 112, /* 664-671 */
594, 950, 1149, 1107, 768, 194, -479, -1097, /* 672-679 */
-1466, -1412, -915, -114, 795, 1532, 1843, 1624, /* 680-687 */
881, -228, -1347, -2082, -2183, -1602, -460, 894, /* 688-695 */
1973, 2407, 2082, 1114, -193, -1436, -2211, -2283, /* 696-703 */
-1686, -623, 611, 1675, 2269, 2190, 1433, 262, /* 704-711 */
-958, -1898, -2344, -2176, -1387, -133, 1217, 2219, /* 712-719 */
2583, 2214, 1199, -172, -1501, -2414, -2641, -2116, /* 720-727 */
-980, 455, 1759, 2553, 2626, 1972, 786, -620, /* 728-735 */
-1854, -2574, -2610, -1975, -802, 614, 1918, 2781, /* 736-743 */
2938, 2263, 839, -926, -2483, -3373, -3312, -2239, /* 744-751 */
-410, 1576, 3113, 3769, 3331, 1907, -113, -2140, /* 752-759 */
-3563, -3940, -3154, -1412, 763, 2658, 3719, 3724, /* 760-767 */
2724, 977, -1052, -2796, -3769, -3693, -2572, -671, /* 768-775 */
1466, 3179, 3999, 3667, 2241, 136, -2019, -3575, /* 776-783 */
-4109, -3463, -1784, 463, 2581, 3914, 4069, 2992, /* 784-791 */
1023, -1237, -3131, -4086, -3794, -2347, -189, 2028, /* 792-799 */
3621, 4116, 3379, 1609, -673, -2760, -4000, -3994, /* 800-807 */
-2734, -640, 1625, 3381, 4069, 3480, 1825, -347, /* 808-815 */
-2351, -3589, -3737, -2817, -1082, 976, 2734, 3657, /* 816-823 */
3492, 2345, 531, -1467, -3071, -3764, -3327, -1906, /* 824-831 */
 85, 2059, 3436, 3809, 3054, 1345, -802, -2672, /* 832-839 */
-3734, -3702, -2560, -660, 1407, 3049, 3792, 3415, /* 840-847 */
2050, 108, -1834, -3266, -3811, -3241, -1699, 349, /* 848-855 */
2309, 3611, 3862, 2979, 1219, -930, -2812, -3849, /* 856-863 */
-3727, -2442, -399, 1728, 3283, 3798, 3125, 1494, /* 864-871 */
-564, -2370, -3355, -3305, -2318, -675, 1185, 2710, /* 872-879 */
3416, 3051, 1696, -217, -2053, -3209, -3324, -2401, /* 880-887 */
-755, 1068, 2539, 3254, 2953, 1726,  -3, -1701, /* 888-895 */
-2886, -3160, -2446, -1013, 723, 2258, 3078, 2896, /* 896-903 */
1775, 116, -1504, -2620, -2918, -2296, -965, 616, /* 904-911 */
1931, 2600, 2475, 1655, 395, -967, -2021, -2459, /* 912-919 */
-2169, -1237,  71, 1354, 2197, 2372, 1816, 684, /* 920-927 */
-645, -1713, -2201, -2022, -1252, -128, 1036, 1861, /* 928-935 */
2065, 1595, 646, -464, -1392, -1851, -1735, -1103, /* 936-943 */
-142, 860, 1591, 1826, 1491, 654, -424, -1357, /* 944-951 */
-1838, -1725, -1061, -19, 1059, 1793, 1935, 1443, /* 952-959 */
511, -569, -1470, -1942, -1845, -1199, -202, 850, /* 960-967 */
1655, 2018, 1831, 1102,  26, -1076, -1872, -2112, /* 968-975 */
-1731, -855, 245, 1253, 1905, 2034, 1599, 714, /* 976-983 */
-353, -1316, -1921, -1995, -1514, -625, 426, 1355, /* 984-991 */
1907, 1926, 1419, 544, -476, -1388, -1919, -1904, /* 992-999 */
-1360, -429, 635, 1528, 1976, 1820, 1107,  75, /* 1000-1007 */
-942, -1632, -1825, -1503, -778, 127, 962, 1551, /* 1008-1015 */
1748, 1471, 760, -176, -1063, -1669, -1806, -1430, /* 1016-1023 */
-633, 333, 1167, 1665, 1712, 1298, 520, -411, /* 1024-1031 */
-1219, -1680, -1667, -1177, -330, 613, 1374, 1740, /* 1032-1039 */
1580, 944,  25, -893, -1522, -1682, -1334, -601, /* 1040-1047 */
290, 1024, 1407, 1391, 1026, 428, -302, -944, /* 1048-1055 */
-1303, -1292, -938, -343, 348, 949, 1320, 1348, /* 1056-1063 */
983, 282, -525, -1186, -1500, -1366, -820, -54, /* 1064-1071 */
708, 1302, 1545, 1358, 751, -97, -972, -1571, /* 1072-1079 */
-3022, -3641, -913, 3551, 6952, 6960, 3146, -2844, /* 1080-1087 */
-8033, -9743, -6890, -579, 6396, 10806, 10469, 5325, /* 1088-1095 */
-2466, -9467, -12499, -10059, -3047, 5579, 12018, 13338, /* 1096-1103 */
8802, 240, -8715, -14177, -13668, -7225, 2533, 11512, /* 1104-1111 */
15868, 13599, 5451, -5293, -14137, -17265, -13224, -3562, /* 1112-1119 */
7801, 16171, 18024, 12533, 1875, -9679, -17471, -18325, /* 1120-1127 */
-11779, -371, 11291, 18458, 18215, 10640, -1234, -12583, /* 1128-1135 */
-18811, -17452, -9148, 2709, 13374, 18616, 16331, 7480, /* 1136-1143 */
-4286, -14105, -17975, -14481, -5201, 5957, 14382, 16731, /* 1144-1151 */
12218, 2876, -7401, -14425, -15385, -9961, -474, 9029, /* 1152-1159 */
14580, 13943, 7460, -2078, -10613, -14619, -12475, -5100, /* 1160-1167 */
4428, 12115, 14729, 11137, 2826, -6728, -13513, -14665, /* 1168-1175 */
-9675, -618, 8730, 14498, 14300, 8249, -1174, -10167, /* 1176-1183 */
-15095, -13915, -7085, 2616, 11285, 15421, 13359, 5833, /* 1184-1191 */
-3973, -11882, -14903, -12043, -4592, 4408, 11453, 13703, /* 1192-1199 */
10522, 3649, -4125, -10087, -11964, -8977, -2736, 4057, /* 1200-1207 */
8696, 9614, 6796, 1612, -3730, -7209, -7573, -4905, /* 1208-1215 */
-512, 3747, 6130, 5774, 3044, -755, -3963, -5299, /* 1216-1223 */
-4330, -1519, 1877, 4402, 4987, 3381, 277, -3011, /* 1224-1231 */
-5061, -4975, -2729, 730, 3987, 5692, 5091, 2402, /* 1232-1239 */
-1334, -4657, -6239, -5388, -2337, 1735, 5163, 6601, /* 1240-1247 */
5486, 2265, -1820, -5216, -6619, -5533, -2372, 1677, /* 1248-1255 */
5107, 6581, 5541, 2418, -1582, -4897, -6325, -5323, /* 1256-1263 */
-2308, 1491, 4626, 5899, 4862, 1993, -1566, -4411, /* 1264-1271 */
-5373, -4145, -1329, 1855, 4117, 4615, 3242, 615, /* 1272-1279 */
-2141, -3913, -4017, -2373, 263, 2746, 4006, 3469, /* 1280-1287 */
1382, -1339, -3469, -4058, -2867, -459, 2204, 3994, /* 1288-1295 */
4111, 2507, -215, -2930, -4506, -4301, -2324, 669, /* 1296-1303 */
3463, 4933, 4450, 2198, -929, -3708, -5037, -4423, /* 1304-1311 */
-2136, 928, 3612, 4861, 4251, 2056, -859, -3309, /* 1312-1319 */
-4422, -3803, -1744, 870, 3016, 3866, 3141, 1227, /* 1320-1327 */
-1054, -2788, -3297, -2441, -609, 1395, 2673, 2705, /* 1328-1335 */
1579, -167, -1736, -2475, -2100, -745, 941, 2204, /* 1336-1343 */
2472, 1583, -89, -1829, -2837, -2578, -1114, 939, /* 1344-1351 */
2740, 3471, 2755, 810, -1646, -3610, -4186, -3057, /* 1352-1359 */
-602, 2235, 4281, 4696, 3224, 462, -2495, -4535, /* 1360-1367 */
-4842, -3290, -505, 2438, 4450, 4778, 3308, 622, /* 1368-1375 */
-2220, -4137, -4457, -3139, -723, 1847, 3596, 3923, /* 1376-1383 */
2788, 737, -1440, -2921, -3173, -2221, -572, 1081, /* 1384-1391 */
2127, 2222, 1474, 291, -787, -1345, -1247, -635, /* 1392-1399 */
122, 668, 780, 434, -180, -716, -842, -441, /* 1400-1407 */
293, 991, 1308, 1049, 223, -838, -1679, -1947, /* 1408-1415 */
-1426, -219, 1249, 2358, 2584, 1802, 253, -1484, /* 1416-1423 */
-2734, -2992, -2109, -409, 1470, 2820, 3126, 2284, /* 1424-1431 */
613, -1253, -2617, -2982, -2266, -780, 917, 2214, /* 1432-1439 */
2687, 2211, 976, -547, -1811, -2387, -2116, -1116, /* 1440-1447 */
235, 1432, 2053, 1903, 1083, -63, -1097, -1676, /* 1448-1455 */
-1606, -921,  69, 962, 1396, 1224, 563, -275, /* 1456-1463 */
-908, -1102, -817, -216, 414, 829, 864, 518, /* 1464-1471 */
-58, -591, -792, -591, -122, 384, 705, 681, /* 1472-1479 */
289, -270, -737, -897, -624,  11, 742, 1223, /* 1480-1487 */
1218, 661, -299, -1268, -1807, -1631, -739, 565, /* 1488-1495 */
1753, 2298, 1962, 831, -679, -1989, -2593, -2240, /* 1496-1503 */
-1050, 559, 1990, 2737, 2503, 1316, -364, -1870, /* 1504-1511 */
-2676, -2531, -1481,  83, 1568, 2419, 2380, 1519, /* 1512-1519 */
159, -1183, -2026, -2110, -1455, -290, 915, 1676, /* 1520-1527 */
1727, 1135, 197, -694, -1226, -1271, -838, -150, /* 1528-1535 */
491, 854, 857, 519,  33, -367, -543, -412, /* 1536-1543 */
-82, 265, 405, 267, -45, -394, -577, -473, /* 1544-1551 */
-105, 386, 759, 835, 597,  98, -498, -976, /* 1552-1559 */
-1120, -834, -227, 503, 1134, 1378, 1097, 390, /* 1560-1567 */
-484, -1187, -1499, -1323, -679, 246, 1127, 1632, /* 1568-1575 */
1582, 976,  19, -959, -1627, -1742, -1234, -263, /* 1576-1583 */
789, 1515, 1677, 1226, 337, -576, -1214, -1396, /* 1584-1591 */
-1055, -382, 379, 925, 1046, 802, 322, -207, /* 1592-1599 */
-568, -645, -512, -290, -38, 224, 365, 322, /* 1600-1607 */
188,  62, -26, -49, -32, -71, -66, -117, /* 1608-1615 */
-118, -858, -1359, 751, 3629, 3692, -185, -5078, /* 1616-1623 */
-6477, -2350, 4548, 8687, 6221, -1757, -9465, -10678, /* 1624-1631 */
-3618, 7146, 13664, 10537, -642, -12130, -15592, -8173, /* 1632-1639 */
5169, 15133, 14602, 3749, -9772, -16128, -10671, 2562, /* 1640-1647 */
13901, 14974, 4849, -9151, -16858, -12479, 1271, 14659, /* 1648-1655 */
17969, 8587, -7018, -17834, -16245, -3416, 11696, 18555, /* 1656-1663 */
12311, -2621, -15571, -17275, -6605, 8731, 17734, 14090, /* 1664-1671 */
534, -13362, -17795, -9651, 5243, 16209, 15482, 3734, /* 1672-1679 */
-10449, -16837, -11002, 2760, 14570, 15846, 5531, -9037, /* 1680-1687 */
-17369, -13319, 369, 13960, 17868, 9391, -5546, -16560, /* 1688-1695 */
-16060, -4507, 9876, 16965, 11947, -1242, -13008, -15090, /* 1696-1703 */
-6346, 6717, 14650, 11783, 270, -11475, -14876, -7322, /* 1704-1711 */
5710, 14794, 13391, 2369, -10584, -16305, -10692, 2444, /* 1712-1719 */
13969, 15808, 6769, -6727, -15326, -13277, -2103, 10134, /* 1720-1727 */
14765, 8941, -2939, -12267, -12387, -3475, 7750, 13133, /* 1728-1735 */
8854, -2091, -11969, -13387, -5013, 7578, 15637, 12900, /* 1736-1743 */
716, -12657, -17728, -10593, 4068, 16102, 17026, 6087, /* 1744-1751 */
-9022, -17543, -13479, 123, 13440, 16914, 8191, -6336, /* 1752-1759 */
-16276, -14489, -2274, 11453, 16750, 9899, -3987, -14759, /* 1760-1767 */
-14567, -3591, 10144, 16578, 10716, -3458, -15760, -17108, /* 1768-1775 */
-6100, 9761, 19400, 15962, 1646, -13827, -20004, -12803, /* 1776-1783 */
2620, 15527, 17276, 7228, -7024, -15253, -11986, -116, /* 1784-1791 */
11350, 13898, 5710, -7104, -14907, -11696, 460, 12866, /* 1792-1799 */
16523, 8618, -5544, -16174, -15792, -4581, 9700, 17124, /* 1800-1807 */
12576, -576, -12958, -15986, -7797, 5702, 15009, 13620, /* 1808-1815 */
2698, -9946, -15417, -9995, 2178, 12350, 13451, 5003, /* 1816-1823 */
-6641, -12904, -9290, 1334, 10966, 12250, 3937, -8013, /* 1824-1831 */
-14818, -11169, 918, 13257, 17216, 9773, -4315, -15639, /* 1832-1839 */
-16725, -7151, 6337, 14668, 12786, 2785, -7806, -11571, /* 1840-1847 */
-6429, 3169, 9633, 7950, -537, -9297, -11452, -4881, /* 1848-1855 */
6043, 13602, 12155, 2298, -9385, -14878, -10434, 769, /* 1856-1863 */
11015, 13377, 6446, -4665, -12069, -10621, -1436, 8806, /* 1864-1871 */
12771, 7676, -2853, -11460, -12248, -4844, 5449, 11563, /* 1872-1879 */
9593, 1395, -6844, -9286, -4599, 3277, 8105, 6062, /* 1880-1887 */
-1416, -8665, -9923, -3559, 6446, 13131, 11540, 2290, /* 1888-1895 */
-8807, -14618, -11514, -1669, 8507, 12637, 8678,  59, /* 1896-1903 */
-7060, -8135, -3267, 3204, 6149, 3437, -2679, -7329, /* 1904-1911 */
-6536, -346, 7059, 10357, 6916, -1228, -8727, -10664, /* 1912-1919 */
-5836, 2433, 8533, 8484, 2692, -4466, -7861, -5173, /* 1920-1927 */
1499, 7169, 7611, 2381, -4921, -9200, -7435, -768, /* 1928-1935 */
6336, 9209, 6201, -329, -5840, -6851, -3188, 2056, /* 1936-1943 */
4821, 3161, -1391, -4974, -4409, 283, 5827, 8063, /* 1944-1951 */
4889, -2099, -8483, -9984, -5431, 2391, 8619, 9479, /* 1952-1959 */
4803, -2101, -6795, -6631, -2445, 2393, 4448, 2639, /* 1960-1967 */
-1108, -3553, -2644, 994, 4520, 4988, 1657, -3352, /* 1968-1975 */
-6599, -5688, -990, 4474, 7087, 5135, -70, -5022, /* 1976-1983 */
-6427, -3507, 1568, 5271, 5156, 1496, -2984, -5140, /* 1984-1991 */
-3612, 350, 3863, 4485, 1923, -1870, -4113, -3208, /* 1992-1999 */
 77, 3215, 3837, 1454, -2206, -4424, -3422, 279, /* 2000-2007 */
4144, 5350, 2853, -1748, -5351, -5521, -2134, 2607, /* 2008-2015 */
5618, 4992, 1303, -2941, -5011, -3731, -270, 2854, /* 2016-2023 */
3609, 1785, -991, -2554, -1784, 598, 2586, 2418, /* 2024-2031 */
 -7, -2969, -4193, -2524, 1214, 4604, 5281, 2608, /* 2032-2039 */
-1808, -5155, -5298, -2188, 2099, 4766, 4204, 1073, /* 2040-2047 */
-2326, -3741, -2433, 404, 2571, 2549, 520, -1862, /* 2048-2055 */
-2716, -1396, 1099, 2876, 2541, 273, -2320, -3339, /* 2056-2063 */
-1971, 868, 3200, 3367, 1210, -1848, -3766, -3231, /* 2064-2071 */
-546, 2531, 3971, 2874,  34, -2665, -3555, -2235, /* 2072-2079 */
271, 2241, 2474, 1082, -687, -1460, -778, 612, /* 2080-2087 */
1406, 789, -917, -2440, -2443, -568, 2125, 3828, /* 2088-2095 */
3263, 629, -2493, -4177, -3397, -685, 2210, 3484, /* 2096-2103 */
2526, 237, -1705, -2071, -903, 687, 1399, 703, /* 2104-2111 */
-787, -1816, -1449, 193, 1962, 2556, 1480, -594, /* 2112-2119 */
-2274, -2475, -1115, 821, 1986, 1659, 207, -1228, /* 2120-2127 */
-1592, -640, 900, 1864, 1476, -56, -1713, -2371, /* 2128-2135 */
-1527, 292, 1901, 2285, 1310, -299, -1477, -1552, /* 2136-2143 */
-685, 381, 887, 557, -231, -760, -543, 280, /* 2144-2151 */
1094, 1272, 611, -526, -1446, -1566, -824, 264, /* 2152-2159 */
1021, 1088, 614,  71, -140,  13, 197,  18, /* 2160-2167 */
-580, -1154, -1164, -417, 758}; /* 2168-2172 */


const signed short wavedata1[WAVE1_NUM_ELEMENTS] = {
-851, -591, -204, 198, 504, 628, 535, 255, /* 0-7 */
-131, -517, -794, -886, -772, -487, -116, 233, /* 8-15 */
460, 500, 341,  30, -346, -681, -880, -889, /* 16-23 */
-707, -386, -19, 292, 460, 440, 241, -78, /* 24-31 */
-423, -694, -814, -748, -514, -180, 159, 408, /* 32-39 */
497, 402, 150, -185, -508, -728, -781, -656, /* 40-47 */
-385, -49, 252, 453, 454, 339,  -2, -225, /* 48-55 */
-666, -538, -1051, 2787, 6961, 8554, 10946, 12579, /* 56-63 */
14191, 15204, 16040, 16572, 17082, 17576, 18136, 18669, /* 64-71 */
19033, 19010, 18382, 16982, 14742, 11725, 8121, 4207, /* 72-79 */
296, -3338, -6516, -9186, -11425, -13396, -15293, -17265, /* 80-87 */
-19359, -21491, -23452, -24956, -25715, -25519, -24299, -22162, /* 88-95 */
-19373, -16306, -13351, -10829, -8916, -7609, -6737, -6022, /* 96-103 */
-5168, -3954, -2305, -330, 1706, 3451, 4557, 4786, /* 104-111 */
4085, 2610, 699, -1210, -2688, -3424, -3306, -2449, /* 112-119 */
-1158, 151, 1077, 1338, 858, -215, -1545, -2705, /* 120-127 */
-3296, -3067, -1989, -276, 1672, 3369, 4373, 4413, /* 128-135 */
3462, 1749, -294, -2155, -3371, -3659, -2990, -1599, /* 136-143 */
 85, 1552, 2363, 2263, 1265, -357, -2139, -3557, /* 144-151 */
-4173, -3757, -2364, -317, 1875, 3650, 4549, 4340, /* 152-159 */
3085, 1122, -1022, -2780, -3696, -3548, -2416, -651, /* 160-167 */
1220, 2638, 3175, 2649, 1184, -829, -2833, -4261, /* 168-175 */
-4694, -3975, -2263,  14, 2272, 3928, 4557, 4015, /* 176-183 */
2468, 355, -1738, -3242, -3753, -3152, -1633, 353, /* 184-191 */
2222, 3420, 3582, 2629, 798, -1425, -3440, -4693, /* 192-199 */
-4832, -3805, -1874, 454, 2569, 3921, 4171, 3282, /* 200-207 */
1530, -581, -2451, -3558, -3599, -2572, -777, 1267, /* 208-215 */
2970, 3837, 3599, 2296, 265, -1958, -3775, -4702, /* 216-223 */
-4491, -3205, -1194, 997, 2784, 3700, 3523, 2336, /* 224-231 */
498, -1456, -2964, -3598, -3176, -1819,  91, 2015, /* 232-239 */
3408, 3871, 3259, 1726, -323, -2343, -3797, -4307, /* 240-247 */
-3750, -2299, -363, 1524, 2849, 3265, 2684, 1295, /* 248-255 */
-489, -2147, -3203, -3351, -2543, -1002, 844, 2483, /* 256-263 */
3459, 3497, 2583, 963, -928, -2583, -3568, -3636, /* 264-271 */
-2794, -1298, 420, 1881, 2683, 2617, 1723, 273, /* 272-279 */
-1308, -2560, -3120, -2823, -1744, -176, 1447, 2684, /* 280-287 */
3198, 2851, 1745, 187, -1401, -2593, -3083, -2761, /* 288-295 */
-1747, -349, 1024, 1981, 2254, 1775, 689, -686, /* 296-303 */
-1954, -2748, -2840, -2196, -989, 451, 1734, 2517, /* 304-311 */
2598, 1968, 815, -533, -1705, -2384, -2401, -1775, /* 312-319 */
-705, 486, 1450, 1908, 1727, 962, -170, -1346, /* 320-327 */
-2233, -2579, -2287, -1436, -260, 920, 1787, 2115, /* 328-335 */
1830, 1031, -47, -1091, -1812, -2014, -1655, -854, /* 336-343 */
148, 1052, 1595, 1616, 1105, 205, -831, -1715, /* 344-351 */
-2200, -2152, -1589, -667, 359, 1210, 1661, 1603, /* 352-359 */
1072, 236, -658, -1349, -1641, -1455, -852, -10, /* 360-367 */
821, 1401, 1558, 1243, 540, -358, -1205, -1770, /* 368-375 */
-1903, -1575, -886, -31, 749, 1242, 1318, 972, /* 376-383 */
314, -458, -1117, -1472, -1420, -979, -277, 484, /* 384-391 */
1087, 1356, 1214, 697, -54, -835, -1433, -1692, /* 392-399 */
-1548, -1052, -349, 359, 876, 1062, 877, 381, /* 400-407 */
-272, -888, -1288, -1353, -1062, -495, 189, 800, /* 408-415 */
1167, 1187, 857, 265, -426, -1031, -1390, -1417, /* 416-423 */
-1116, -583,  24, 530, 795, 746, 406, -124, /* 424-431 */
-687, -1119, -1294, -1158, -746, -168, 421, 863, /* 432-439 */
1042, 916, 526, -17, -563, -964, -1118, -995, /* 440-447 */
-639, -161, 298, 606, 676, 488,  98, -385, /* 448-455 */
-824, -1099, -1133, -919, -515, -31, 405, 679, /* 456-463 */
726, 541, 184, -242, -618, -844, -864, -680, /* 464-471 */
-352,  24, 339, 508, 483, 275, -58, -422, /* 472-479 */
-720, -872, -841, -639, -322,  23, 308, 461, /* 480-487 */
450, 286,  21, -270, -508, -634, -619, -477, /* 488-495 */
-252, -11, 179, 267, 230,  81, -139, -370, /* 496-503 */
-554, -647, -627, -502, -308, -92,  94, 209, /* 504-511 */
234, 173,  47, -105, -241}; /* 512-516 */
