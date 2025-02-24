FROM ubuntu:latest

ENV BINARY_NAME="terragrunt"

RUN apt update && apt install wget -y && apt install curl -y && apt install jq -y
RUN apt-get update && apt-get install -y gnupg software-properties-common 
RUN wget -O- https://apt.releases.hashicorp.com/gpg | \
    gpg --dearmor | \
    tee /usr/share/keyrings/hashicorp-archive-keyring.gpg > /dev/null
RUN gpg --no-default-keyring \
    --keyring /usr/share/keyrings/hashicorp-archive-keyring.gpg \
    --fingerprint
RUN echo "deb [signed-by=/usr/share/keyrings/hashicorp-archive-keyring.gpg] \
    https://apt.releases.hashicorp.com $(lsb_release -cs) main" | \
    tee /etc/apt/sources.list.d/hashicorp.list
RUN apt update && apt-get install terraform -y

RUN curl -sL "https://github.com/gruntwork-io/terragrunt/releases/download/v0.73.11/terragrunt_linux_amd64" -o "$BINARY_NAME"

RUN chmod u+x terragrunt && mv terragrunt /usr/bin/terragrunt

# ENTRYPOINT ["terragrunt"]

