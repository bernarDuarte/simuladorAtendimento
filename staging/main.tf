terraform {
  backend "s3" {}
}

module ecr {
    source = "github.com/bernarDuarte/testeModuleAutomation.git"
    repository_name = var.repository_name
}
