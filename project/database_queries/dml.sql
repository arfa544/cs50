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
(1,	1,	180,	80,	24.69,	'2022 Dec 18 12:32:43'),
(	2	,	1	,	180	,	94	,	29.01	,	2022-12-14	)	;