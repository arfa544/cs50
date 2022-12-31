-- Insert values in users table
INSERT INTO users (user_id, user_name, password, email) VALUES
(1,'Kathryn Castillo',12,'Kathryn@gmail.com'),
(2,'Kai Alexander',12,'Kai@gmail.com'),
(3,'Lyla Fleming',12,'Lyla@gmail.com'),
(4,'Fernando Barrera',12,'Fernando@gmail.com'),
(5,'Beatrice Nielsen',12,'Beatrice@gmail.com'),
(6,'Tru Wade',12,'Tru@gmail.com'),
(7,'Evie Hahn',12,'Evie@gmail.com'),
(8,'Kabir Boone',12,'Kabir@gmail.com'),
(9,'Mariam Christian',12,'Mariam@gmail.com'),
(10,'Ledger Estrada',12,'Ledger@gmail.com');

-- Insert values in family table
INSERT INTO family (family_id, family_name) VALUES
(1,'Royals'),
(2,'Kings');

-- Insert values in family_user_mapping table
INSERT INTO family_user_mapping (family_id, user_id) VALUES
(1, 1),
(1, 2),
(1, 3),
(1, 4),
(1, 5),
(1, 6),
(1, 7),
(2, 8),
(2, 9),
(2, 10);

-- Insert values in records table
INSERT INTO records (profile_id, user_id, height, weight, bmi, record_date) VALUES
(	1	,	1	,	140.5	,	65	,	32.93	,	'2018 02 01 00:00:00'	)	,
(	2	,	1	,	150	,	69	,	30.67	,	'2018 08 01 01:00:00'	)	,
(	3	,	1	,	150	,	75	,	33.33	,	'2019 02 01 04:05:00'	)	,
(	4	,	1	,	165	,	78	,	28.65	,	'2020 08 01 00:00:00'	)	,
(	5	,	1	,	170.5	,	77	,	26.49	,	'2021 02 01 11:00:30'	)	,
(	6	,	1	,	180	,	79	,	24.38	,	'2022 02 01 00:00:00'	)	,
(	7	,	1	,	180	,	80	,	24.69	,	'2022 12 12 07:50:20'	)	,
(	8	,	2	,	105	,	20	,	18.14	,	'2016 11 11 00:00:00'	)	,
(	9	,	2	,	120	,	27	,	18.75	,	'2017 10 10 00:00:00'	)	,
(	10	,	2	,	130	,	34	,	20.12	,	'2018 09 08 00:00:00'	)	,
(	11	,	2	,	150	,	42	,	18.67	,	'2019 08 07 00:00:00'	)	,
(	12	,	2	,	155	,	50	,	20.81	,	'2020 07 05 00:00:00'	)	,
(	13	,	2	,	163.5	,	60	,	22.44	,	'2021 06 03 00:00:00'	)	,
(	14	,	3	,	170	,	65	,	22.49	,	'2016 11 07 07:32:43'	)	,
(	15	,	3	,	172	,	67	,	22.65	,	'2017 11 07 07:32:43'	)	,
(	16	,	3	,	174	,	70	,	23.12	,	'2018 11 07 07:32:43'	)	,
(	17	,	3	,	176	,	72	,	23.24	,	'2019 11 07 07:32:43'	)	,
(	18	,	3	,	177.5	,	75	,	23.8	,	'2020 11 07 07:32:43'	)	,
(	19	,	3	,	179	,	84	,	26.22	,	'2021 11 07 07:32:43'	)	,
(	20	,	3	,	181	,	77	,	23.5	,	'2022 11 07 07:32:43'	)	,
(	21	,	4	,	150	,	60	,	26.67	,	'2018 11 07 07:32:43'	)	,
(	22	,	4	,	160	,	57	,	22.27	,	'2019 11 07 07:32:43'	)	,
(	23	,	4	,	160	,	59	,	23.05	,	'2020 11 07 07:32:43'	)	,
(	24	,	4	,	170	,	60	,	20.76	,	'2021 11 07 07:32:43'	)	,
(	25	,	4	,	180	,	70	,	21.6	,	'2022 11 07 07:32:43'	)	,
(	26	,	5	,	140	,	60	,	30.61	,	'2020 05 05 10:00:00'	)	,
(	27	,	5	,	145	,	55	,	26.16	,	'2020 11 05 01:00:00'	)	,
(	28	,	5	,	140	,	50	,	25.51	,	'2021 05 04 16:00:00'	)	,
(	29	,	5	,	135	,	40	,	21.95	,	'2021 11 04 07:00:00'	)	,
(	30	,	5	,	140	,	38	,	19.39	,	'2022 05 03 22:00:00'	)	,
(	31	,	6	,	120	,	45	,	31.25	,	'2017 10 10 00:00:00'	)	,
(	32	,	6	,	125	,	50	,	32	,	'2018 10 10 08:30:45'	)	,
(	33	,	6	,	130	,	52	,	30.77	,	'2019 10 10 17:01:30'	)	,
(	34	,	6	,	135	,	55	,	30.18	,	'2020 10 11 01:32:15'	)	,
(	35	,	6	,	140	,	57	,	29.08	,	'2021 10 11 10:03:00'	)	,
(	36	,	6	,	145	,	66	,	31.39	,	'2022 10 11 18:33:45'	)	,
(	37	,	7	,	160	,	55	,	21.48	,	'2017 01 07 07:32:43'	)	,
(	38	,	7	,	164	,	57	,	21.19	,	'2018 01 07 09:58:33'	)	,
(	39	,	7	,	172	,	62	,	20.96	,	'2019 01 07 12:24:23'	)	,
(	40	,	7	,	174	,	65	,	21.47	,	'2020 01 07 14:50:13'	)	,
(	41	,	7	,	176	,	67	,	21.63	,	'2021 01 07 17:16:03'	)	,