(defn main-function []
    (def number-of-nodes (read-string (read-line)))

    (dotimes [i (- number-of-nodes 1)]
        (def source (read-string (read-line)))
        (def destination (read-string (read-line)))
    )
)

(main-function)
