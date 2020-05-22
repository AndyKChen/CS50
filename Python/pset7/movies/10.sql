SELECT people.name
FROM people
INNER JOIN directors ON people.id = directors.person_id
INNER JOIN ratings ON movies.id = ratings.movie_id
INNER JOIN movies ON directors.movie_id = movies.id
WHERE ratings.rating >= 9