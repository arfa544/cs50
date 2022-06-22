SELECT count(name) FROM people
WHERE id in (SELECT movie_id FROM stars JOIN people ON stars.person_id = people.id
WHERE name = "Kevin Bacon" AND birth = 1958);