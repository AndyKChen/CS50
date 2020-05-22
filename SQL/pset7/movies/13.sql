SELECT DISTINCT(people.name)
FROM people
INNER JOIN stars ON people.id = stars.person_id
INNER join movies ON stars.movie_id = movies.id
WHERE name != "Kevin Bacon" AND movies.id IN(
    SELECT DISTINCT(movies.id)
    FROM people
    INNER JOIN stars ON people.id = stars.person_id
    INNER join movies ON stars.movie_id = movies.id
    WHERE (people.name = "Kevin Bacon" AND people.birth = 1958)
)

-- ALTERNATE SOLUTION
SELECT name  --Get name where the id is equal to the id in stars in the next step
FROM people
WHERE name != "Kevin Bacon" AND id IN (
    SELECT person_id  --Get all the star's ids who are in the movies in which Kevin Bacon starred in
    FROM stars
    WHERE stars.movie_id IN (
            SELECT movie_id  --Get all movie ids where Kevin Bacon starred in
            FROM stars
            Where stars.person_id IN (
                SELECT id       --Get Kevin Bacon's ID
                FROM people
                WHERE people.name = "Kevin Bacon" AND birth = 1958)
                            )
            )

