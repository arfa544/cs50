-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";

--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today
--with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

SELECT transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28 AND transcript like "%bakery%";

--1.Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
--  If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
SELECT name FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25;
--Suspects
-- +---------+
-- | Vanessa |
-- | Bruce   |
-- | Barry   |
-- | Luca    |
-- | Sofia   |
-- | Iman    |
-- | Diana   |
-- | Kelsey  |
-- +---------+

--2.I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
--  I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
SELECT name from people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
--New suspects
-- +---------+
-- | Bruce   |
-- | Diana   |
-- | Brooke  |
-- | Kenny   |
-- | Iman    |
-- | Luca    |
-- | Taylor  |
-- | Benista |
-- +---------+

--3.As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call,
--  I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
--  The thief then asked the person on the other end of the phone to purchase the flight ticket.
SELECT name from people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id = (SELECT id FROM flights
WHERE year = 2021 AND month = 7 AND day = 29
ORDER BY hour,minute LIMIT 1);
--New suspects
-- +--------+
-- | Doris  |
-- | Sofia  |
-- | Bruce  |
-- | Edward |
-- | Kelsey |
-- | Taylor |
-- | Kenny  |
-- | Luca   |
-- +--------+

--Common suspects from above three conditions are
--Bruce, Luca

SELECT name, duration, caller, receiver from phone_calls
JOIN people ON phone_calls.caller = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
-- +---------+----------+----------------+----------------+
-- |  name   | duration |     caller     |    receiver    |
-- +---------+----------+----------------+----------------+
-- | Sofia   | 51       | (130) 555-0289 | (996) 555-8899 |
-- | Kelsey  | 36       | (499) 555-9472 | (892) 555-8872 |
-- | Bruce   | 45       | (367) 555-5533 | (375) 555-8161 |
-- | Kelsey  | 50       | (499) 555-9472 | (717) 555-1342 |
-- | Taylor  | 43       | (286) 555-6063 | (676) 555-6554 |
-- | Diana   | 49       | (770) 555-1861 | (725) 555-3243 |
-- | Carina  | 38       | (031) 555-6622 | (910) 555-3251 |
-- | Kenny   | 55       | (826) 555-1652 | (066) 555-9701 |
-- | Benista | 54       | (338) 555-6650 | (704) 555-2131 |
-- +---------+----------+----------------+----------------+

--Here caller is Bruce but not Luca
--Hence the thief is BRUCE.

--Catch the accomplice using the receiver number:
SELECT * FROM people
WHERE phone_number = "(375) 555-8161";
-- --------+-------+----------------+-----------------+---------------+
-- |   id   | name  |  phone_number  | passport_number | license_plate |
-- +--------+-------+----------------+-----------------+---------------+
-- | 864400 | Robin | (375) 555-8161 |                 | 4V16VO0       |
-- +--------+-------+----------------+-----------------+---------------+

--Hence accomplice is ROBIN.

SELECT city FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE year = 2021 AND month = 7 AND day = 29
ORDER BY hour, minute
LIMIT 1;
-- +---------------+
-- |     city      |
-- +---------------+
-- | New York City |
-- +---------------+

--Hence the city the thief escaped to is NEW YORK CITY.