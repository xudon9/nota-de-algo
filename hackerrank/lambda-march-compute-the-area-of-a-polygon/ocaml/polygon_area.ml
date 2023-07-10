(* https://www.hackerrank.com/challenges/lambda-march-compute-the-area-of-a-polygon/problem *)
open Core

let read_int () =
  Out_channel.(flush stdout);
  Scanf.scanf " %d" Fun.id

let read_point () =
  let x = read_int () in
  let y = read_int () in
  (x, y)

let calc_points n =
  let p0 = read_point () in
  let adj (x1, y1) (x2, y2) = (x1 * y2) - (x2 * y1) in
  let rec step acc p1 i =
    if i = 0 then acc + adj p1 p0
    else
      let p2 = read_point () in
      step (adj p1 p2 + acc) p2 (i - 1)
  in
  step 0 p0 (n - 1)

let () =
  read_int () |> calc_points |> abs |> Float.of_int
  |> (fun x -> x /. 2.)
  |> printf "%f\n"
