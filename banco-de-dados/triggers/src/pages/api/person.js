import PersonController from "../../controllers/PersonController";

export default function Handle(req, res) {
  switch (req.method) {
    case "POST":
      PersonController.create(req, res);
      break;
    case "DELETE":
      PersonController.delete(req, res);
    case "GET":
      PersonController.show(req, res);
  }
}

export const config = {
  api: {
    externalResolver: true,
  },
};
