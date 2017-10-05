(defn gcd [m n]
    (let [r (mod m n)]
        (if (zero? r)
            n
            (recur n r)
        )
    )
)

(defn count-moves [a b c]
    (defn count-moves-iter [tap sink moves]
        (if (or (= tap c) (= sink c))
            moves
            (cond
                (= tap 0) (recur a sink (inc moves))
                (= sink b) (recur tap 0 (inc moves))
                :else (do
                    (def stream (min tap (- b sink)))
                    (recur (- tap stream) (+ sink stream) (inc moves))
                )
            )
        )
    )

    (count-moves-iter 0 0 0)
)

(defn print-answer [a b c]
    (cond
        (and (> c a) (> c b)) (println "-1")
        (not= (mod c (gcd a b)) 0) (println "-1")
        :else (println (min (count-moves a b c) (count-moves b a c)))
    )
)

(defn main-function []
    (def number-of-test-cases (read-string (read-line)))

    (dotimes [i number-of-test-cases]
        (def a (read-string (read-line)))
        (def b (read-string (read-line)))
        (def c (read-string (read-line)))

        (print-answer a b c)
    )
)

(main-function)
