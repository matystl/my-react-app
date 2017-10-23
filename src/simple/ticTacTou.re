type playerState =
  | Circle
  | Cross;

type state = {
  squares: list Square.squareState,
  player: playerState
};

type actions =
  | Click
  | Toggle;

let component = ReasonReact.reducerComponent "TicTacTou";

let switchPlayer (current: playerState) =>
  switch current {
  | Circle => Cross
  | Cross => Circle
  };

let isEmptySquare (square: Square.squareState) =>
  switch square {
  | Empty => true
  | _ => false
  };

let make _state => {
  ...component,
  initialState: fun () => {
    squares: [
      Square.Empty,
      Square.Empty,
      Square.Empty,
      Square.Empty,
      Square.Empty,
      Square.Empty,
      Square.Empty,
      Square.Empty,
      Square.Empty
    ],
    player: Circle
  },
  reducer: fun action state =>
    switch action {
    | Click => ReasonReact.Update {...state, player: Cross}
    | Toggle => ReasonReact.Update {...state, player: Circle}
    },
  render: fun _self => <div />
};
