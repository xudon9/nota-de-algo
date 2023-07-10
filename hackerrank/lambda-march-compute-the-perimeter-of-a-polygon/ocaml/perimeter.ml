open Core

let read_int () =
  Out_channel.(flush stdout);
  Scanf.scanf " %d" Fun.id

let dist x1 y1 x2 y2 =
  let dx = x1 - x2 in
  let dy = y1 - y2 in
  let d2 = (dx * dx) + (dy * dy) in
  Float.(sqrt (of_int d2))

let () =
  let t = read_int () in
  let x0 = read_int () in
  let y0 = read_int () in
  let rec iter acc x' y' t =
    if t = 0 then acc +. dist x' y' x0 y0
    else
      let x = read_int () in
      let y = read_int () in
      let d = dist x y x' y' in
      iter (acc +. d) x y (t - 1)
  in
  let perimeter = iter 0. x0 y0 (t - 1) in
  printf "%g\n" perimeter
