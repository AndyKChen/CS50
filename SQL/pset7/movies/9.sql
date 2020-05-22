SELECT people.name
FROM people
INNER JOIN stars ON people.id = stars.person_id
INNER JOIN movies ON stars.movie_id = movies.id
WHERE movies.year = 2004
GROUP BY stars.person_id
ORDER BY people.birth